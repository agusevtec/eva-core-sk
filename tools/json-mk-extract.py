#!/usr/bin/env python3
"""
create_docs_from_json.py - Создаёт файлы и директории из JSON-структуры документации
"""

import json
import os
import sys
from pathlib import Path

def create_files_from_json(json_file, base_dir="docs"):
    """
    Создаёт файлы и директории на основе JSON-структуры
    
    Args:
        json_file: путь к JSON-файлу с данными
        base_dir: базовая директория для создания файлов
    """
    
    # Загружаем JSON
    try:
        with open(json_file, 'r', encoding='utf-8') as f:
            data = json.load(f)
    except FileNotFoundError:
        print(f"Ошибка: Файл {json_file} не найден")
        return False
    except json.JSONDecodeError as e:
        print(f"Ошибка парсинга JSON: {e}")
        return False
    
    # Создаём базовую директорию
    base_path = Path(base_dir)
    base_path.mkdir(exist_ok=True)
    
    created_files = 0
    created_dirs = set()
    
    # Обрабатываем каждый файл
    for file_path, content in data.items():
        full_path = base_path / file_path
        
        # Создаём директории для файла
        full_path.parent.mkdir(parents=True, exist_ok=True)
        created_dirs.add(str(full_path.parent))
        
        # Записываем файл
        try:
            with open(full_path, 'w', encoding='utf-8') as f:
                f.write(content)
            print(f"  ✓ {full_path}")
            created_files += 1
        except Exception as e:
            print(f"  ✗ Ошибка при создании {full_path}: {e}")
    
    print("\n" + "="*50)
    print(f"Готово!")
    print(f"Создано директорий: {len(created_dirs)}")
    print(f"Создано файлов: {created_files}")
    print(f"Базовая директория: {base_path.absolute()}")
    
    return True

def main():
    # Парсим аргументы командной строки
    if len(sys.argv) > 1:
        json_file = sys.argv[1]
    else:
        json_file = "docs.json"  # имя по умолчанию
    
    if len(sys.argv) > 2:
        base_dir = sys.argv[2]
    else:
        base_dir = "docs_candidate"
    
    print(f"Создание файлов из {json_file} в {base_dir}/...")
    create_files_from_json(json_file, base_dir)

if __name__ == "__main__":
    main()