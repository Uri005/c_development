#include <SFML/Graphics.hpp>
#include<iostream>

void pause(){
  std::cout<<"Press any key to continue";
  std::getchar();
}

 int main(void)
 {

  sf::RenderWindow window(sf::VideoMode(640,480),"SFML working");
  pause();
  
  return 0;
}

