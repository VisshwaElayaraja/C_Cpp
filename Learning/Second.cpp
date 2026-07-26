#include <iostream>

int main(){
    const double AREA = 987.85;
    double height;
    height = 5;
    std::cout << "Area of building: " << AREA << " sq.meters\n";
    std::cout << "Height of building: " << height << " meters\n";
    
    double volume = AREA * height;
    std::cout << "Volume of building: " << volume << " cu.meters\n";

    

    return 0;
}
// End of Code.
