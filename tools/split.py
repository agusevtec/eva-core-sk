#coding: utf-8
#!/usr/bin/env python3
"""
Скрипт для разделения объединённого файла обратно на отдельные .h и .cpp файлы
Ориентируется на теги <filename> и </filename>
"""

import os
import sys
import re
import argparse
from pathlib import Path

def split_file(combined_file, output_dir=None):
    """
    Разделяет объединённый файл на отдельные файлы по тегам <filename> и </filename>
    
    Args:
        combined_file: путь к объединённому файлу
        output_dir: директория для сохранения (по умолчанию: рядом с combined_file/split)
    """
    combined_path = Path(combined_file)
    if not combined_path.exists():
        print(f"Ошибка: файл {combined_file} не существует")
        return False
    
    # Определяем выходную директорию
    if output_dir is None:
        output_dir = combined_path.parent / 'split'
    else:
        output_dir = Path(output_dir)
    
    # Создаём выходную директорию
    output_dir.mkdir(parents=True, exist_ok=True)
    
    print(f"Выходная директория: {output_dir}")
    
    # Регулярное выражение для поиска тегов
    # Ищет <filename> ... </filename> с возможным содержимым между ними
    tag_pattern = re.compile(r'<([^>]+)>\n?(.*?)</\1>', re.DOTALL | re.MULTILINE)
    
    extracted_files = 0
    
    with open(combined_file, 'r', encoding='utf-8') as f:
        content = f.read()
        
        # Ищем все теги
        for match in tag_pattern.finditer(content):
            filename = match.group(1)
            file_content = match.group(2)
            
            # Убираем возможные пустые строки в начале/конце
            file_content = file_content.strip()
            if not file_content.endswith('\n'):
                file_content += '\n'
            
            # Создаём полный путь к файлу
            # Поддерживаем вложенные директории (если в теге есть пути)
            file_path = output_dir / filename
            
            # Создаём поддиректории если нужно
            file_path.parent.mkdir(parents=True, exist_ok=True)
            
            # Записываем файл
            try:
                with open(file_path, 'w', encoding='utf-8') as out:
                    out.write(file_content)
                print(f"  Создан {file_path}")
                extracted_files += 1
            except Exception as e:
                print(f"  Ошибка при создании {file_path}: {e}")
    
    print(f"Готово! Извлечено файлов: {extracted_files}")
    return True

def main():
    parser = argparse.ArgumentParser(description='Разделение объединённого файла обратно на .h/.cpp')
    parser.add_argument('combined_file', help='Объединённый файл с тегами')
    parser.add_argument('-o', '--output', help='Директория для сохранения (по умолчанию: combined_file_dir/split)')
    
    args = parser.parse_args()
    
    success = split_file(args.combined_file, args.output)
    sys.exit(0 if success else 1)

if __name__ == "__main__":
    main()
