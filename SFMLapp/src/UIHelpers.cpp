#include <SFML/Graphics.hpp>
#include <string>

sf::Text makeText(const std::string& s, const sf::Font& font, unsigned int size) {
    sf::Text t(sf::String(), font, size); // tạo với sf::String() rỗng + font + size
    t.setString(s);
    // hoặc: sf::Text t; t.setFont(font); t.setString(s); t.setCharacterSize(size);
    return t;
}
