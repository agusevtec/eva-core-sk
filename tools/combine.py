#coding: utf-8
#!/usr/bin/env python3
"""
Скрипт для объединения всех .h и .cpp файлов проекта в один файл
Каждый файл обрамляется тегами <filename> и </filename>
"""

import os
import sys
import argparse
from pathlib import Path

def combine_files(source_dir, output_file, extensions=None):
    """
    Объединяет все файлы с указанными расширениями из source_dir в один файл
    
    Args:
        source_dir: исходная директория с файлами
        output_file: имя выходного файла
        extensions: список расширений (по умолчанию ['.h', '.cpp'])
    """
    if extensions is None:
        extensions = ['.h', '.cpp']
    
    source_path = Path(source_dir)
    if not source_path.exists():
        print(f"Ошибка: директория {source_dir} не существует")
        return False
    
    # Собираем все файлы с нужными расширениями
    files_to_combine = []
    for ext in extensions:
        files_to_combine.extend(source_path.glob(f'**/*{ext}'))
    
    # Сортируем для консистентности
    files_to_combine.sort()
    
    if not files_to_combine:
        print(f"Не найдено файлов с расширениями {extensions}")
        return False
    
    print(f"Найдено {len(files_to_combine)} файлов для объединения:")
    for f in files_to_combine[:5]:  # покажем первые 5
        print(f"  {f}")
    if len(files_to_combine) > 5:
        print(f"  ... и ещё {len(files_to_combine) - 5}")
    
    # Объединяем
    with open(output_file, 'w', encoding='utf-8') as out:
        out.write(f"// Combined project file\n")
        out.write(f"// Generated from {source_dir}\n")
        out.write(f"// Total files: {len(files_to_combine)}\n\n")
        
        for file_path in files_to_combine:
            # Относительный путь для тега
            rel_path = file_path.relative_to(source_path)
            
            print(f"Добавляю {rel_path}...")
            
            out.write(f"<{rel_path}>\n")
            
            try:
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                    out.write(content)
                    if not content.endswith('\n'):
                        out.write('\n')
            except Exception as e:
                print(f"  Ошибка при чтении {file_path}: {e}")
                out.write(f"// ERROR reading file: {e}\n")
            
            out.write(f"</{rel_path}>\n\n")
    
    print(f"Готово! Объединённый файл: {output_file}")
    return True

def main():
    parser = argparse.ArgumentParser(description='Объединение .h и .cpp файлов в один')
    parser.add_argument('source_dir', help='Исходная директория с файлами')
    parser.add_argument('-o', '--output', default='combined.txt', 
                        help='Выходной файл (по умолчанию combined.txt)')
    parser.add_argument('--ext', nargs='+', default=['.h', '.cpp'],
                        help='Расширения файлов для объединения')
    
    args = parser.parse_args()
    
    success = combine_files(args.source_dir, args.output, args.ext)
    sys.exit(0 if success else 1)

if __name__ == "__main__":
    main()
