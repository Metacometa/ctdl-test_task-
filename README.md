# Тестовое задание в Цитадель: мониторинг состояния
## Описание
Необходимо разработать конфигурируемое приложение для мониторинга состояния ОС Linux. Указанные в конфигурационном файле метрики должны
сохраняться в файл и/или выводиться в консоль с периодичностью в **N** секунд.

Параметры, которые должны быть конфигурируемы: 
* период снятия метрик системы (в секундах)  
* варьируемый список отслеживаемых метрик системы:  
    * загруженность ядер процессора  
    * объем используемой / свободной оперативной памяти  
    * вывод в консоль и/или в файл

**Примечание:** предполагается, что в будущем функциональность приложения будет расширяться. Например, добавятся новые метрики, а собранные
данные будут отправляться по сети.

## Пример возможного файла конфигурации:
```json
{
  "settings" : {
      "period" : "30"
      },
    "metrics" : [
        {
            "type" : "cpu",
            "ids" : [ 0, 1, 2, 3 ]
        },
        {
            "type" : "memory",
            "spec" : [ "used", "free" ]
        }
    ],
    "outputs" : [
        {
            "type" : "console"
        },
        {
            "type" : "log",
            "path" : "/path/to/file.log"
        }
    ]
}
```
## Детали реализации
Для работы с json-файлами выбрана библиотека **nlohmann/json** из-за простоты, надёжности и производительности.  
Для сборки проекта используется **CMake**.
## Пример запуска
В качестве первого аргумента передаётся путь к файлу конфигурации.
```
./monitoring /path_to_file/config.json
```
