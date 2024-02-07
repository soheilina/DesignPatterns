#include "../headers/FlyWeight.hpp"

//=========================
//  Image Class
//=========================
void Image::setDimension(uint16_t width, uint16_t length){
    m_length = length;
    m_width = width;
}

std::pair<uint16_t, uint16_t> Image::getDimension(){
    return std::make_pair(m_width, m_length);
}

//=========================
//  FlyWeight Class
//=========================
template <typename T>
void FlyWeight::addImage(const std::string name){
    if(m_imageContainer.find(name)==m_imageContainer.end()){
        std::shared_ptr<Image> newImage = std::make_shared<T>();
        m_imageContainer.insert(std::make_pair(name, newImage));
        std::cout << "An image called " << name << " added. ";
        newImage->print();
    }else{
        std::cout << "There exist an image with this name" << std::endl;
    }
}

/*
* @note: templates need to have explict definition for all types they use
*        see here: https://stackoverflow.com/a/1639837
*/
template void FlyWeight::addImage<PNG>(const std::string name);
template void FlyWeight::addImage<JPG>(const std::string name);
template void FlyWeight::addImage<GIF>(const std::string name);

void FlyWeight::deleteImage(const std::string name){
    auto it = m_imageContainer.find(name);
    if(it!=m_imageContainer.end()){
        m_imageContainer.erase(it);
        std::cout << "Deleted the iamge called " << name << std::endl;
    }
    else{
        std::cout << "There is no image with the name " << name << std::endl;
    }
}

std::shared_ptr<Image> FlyWeight::getImage(const std::string name){
    auto it = m_imageContainer.find(name);
    if(it!=m_imageContainer.end()){
        return it->second;
    }
    else{
        std::cout << "There is no image with the name " << name << std::endl;
        return nullptr;
    }
}