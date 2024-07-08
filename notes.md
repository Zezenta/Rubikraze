These two are not the same
This one references the POSITION (will be useful for Rubikraze)
```
#include <iostream>
#include <string>

int main() {
    int nombresito[3] = {5, 6, 7};
    int *puntero = &nombresito[0];
    std::cout << *puntero << std::endl;
    nombresito[0] = 10;
    std::cout << *puntero;
    return 0;
}
```

And this one references the VALUE
```
#include <iostream>
#include <string>

int main() {
    int nombresito[3] = {5, 6, 7};
    int puntero = nombresito[0];
    std::cout << puntero << std::endl;
    nombresito[0] = 10;
    std::cout << puntero;
    return 0;
}
```