# ДЗ 
Требуется реализовать методы в классах в директории `/VeryDynamic/`

### 1. Уменьшение динамических массивов
★★★☆☆

 В этом уроке мы подробно поговорили о том как работает расширение динамического массива, давайте попробуем реализовать также и уменьшение размера согласно стратегии которую мы выбрали (уменьшать при заполненности в 25%).
Дополните код в классе `DynamicArray` так, чтобы он поддерживал удаление любого элемента со сдвигом и уменьшением размера по необходимости. Если переданного индекса в массиве нет — метод должен просто ничего не делать.

Реализуйте метод 
```cpp
void deleteElementAt(int index);
``` 
(вы также можете менять любой другой код в этом классе при необходимости)

### 2. Удаление элементов
★★★☆☆

Добавьте функцию удаления элемента по ключу в нашу реализацию класса HashMap. Не забудьте также об уменьшении низлежащего массива при необходимости и сопутствующем пересчете индексов элементов в нем.
Если такого ключа в HashMap нет — то метод должен просто ничего не делать.

Реализуйте метод 
```cpp
void deleteKey(string key);
```

### 3. Дай мне всё!
★★★☆☆
 
Добавьте в класс HashMap метод который позволяет получить массив всех ключей и отдельно массив всех значений.
```cpp
vector<string> getAllKeys();
vector<string> getAllValues();
```


Не волнуйтесь о времени работы этих методов: главное, чтобы они просто работали :)

