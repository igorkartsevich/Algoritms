# ДЗ

Требуется реализовать методы в `Array.h`, и проверить их тестами `ArrayTest.cpp`

Запуск тестов:
Скомпилировать ArraypTest.cpp и запустить 


## 1. Пройти все курсы

★★★★☆

Всего на платформе Skillbox есть `numCourses` курсов, обозначенных от `0` до `numCourses - 1`. Петр
решил стать самым крутым специалистом и пройти их все. Но оказалось, что курсы зависят друг от
друга. Ему предоставили массив предварительных требований, где `prerequisites[i] = [a, b]`
указывает, что он должен сначала пройти курс `b`, если хочет пройти курс `а`.

Например, пара `[0, 1]` указывает, что для прохождения курса `0` он должны сначала пройти курс `1`.
Верните `true`, если Пётр сможет пройти все курсы. В противном случае верните `false`.


static bool canFinish(int numCourses, const std::vector<std::vector<int>> &prerequisites)

