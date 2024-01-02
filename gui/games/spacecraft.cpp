#include <SFML/Graphics.hpp>
#include <vector>

class NaveEspacial {
public:
    NaveEspacial() : nave(sf::Vector2f(50, 50)) {
        nave.setFillColor(sf::Color::Green);
        nave.setPosition(375, 500);
    }

    void moverDerecha() {
        nave.move(5, 0);
    }

    void moverIzquierda() {
        nave.move(-5, 0);
    }

    void disparar() {
        sf::RectangleShape disparo(sf::Vector2f(5, 20));
        disparo.setFillColor(sf::Color::Red);
        disparo.setPosition(nave.getPosition().x + 22.5, nave.getPosition().y - 20);
        disparos.push_back(disparo);
    }

    void actualizarDisparos() {
        for (auto& disparo : disparos) {
            disparo.move(0, -5);
        }
    }

    const sf::RectangleShape& obtenerNave() const {
        return nave;
    }

    const std::vector<sf::RectangleShape>& obtenerDisparos() const {
        return disparos;
    }

private:
    sf::RectangleShape nave;
    std::vector<sf::RectangleShape> disparos;
};

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Juego de Nave Espacial");
    ventana.setFramerateLimit(60);

    NaveEspacial nave;

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            nave.moverDerecha();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            nave.moverIzquierda();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            nave.disparar();
        }

        nave.actualizarDisparos();

        ventana.clear();

        ventana.draw(nave.obtenerNave());

        for (const auto& disparo : nave.obtenerDisparos()) {
            ventana.draw(disparo);
        }

        ventana.display();
    }

    return 0;
}
