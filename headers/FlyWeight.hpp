#include <iostream>
#include <tuple>
#include <unordered_map>
#include <memory>

/**
 * @breif: This example is based on https://www.youtube.com/watch?v=CY0iCHSH7oM&ab_channel=BradleySward 
 */

enum class ImageType{
    PNG_image,
    JPG_image,
    GIF_image
};

class Image{
public:
    Image()
    : m_width(0)
    , m_length(0)
    {}
    ~Image() = default;

public:
    void setDimension(uint16_t width, uint16_t length);
    std::pair<uint16_t, uint16_t> getDimension();
    virtual ImageType getImageType() = 0;
    virtual void print() = 0;

protected:
    uint16_t m_width;
    uint16_t m_length;
};

class PNG : public Image{
public:
    PNG() : Image(){}
    ~PNG() = default;
public:
    ImageType getImageType() override {
        return ImageType::PNG_image;
    }
    void print() override{
        std::cout << "This is a PNG file." << std::endl;
    }
};

class JPG : public Image{
public:
    JPG() : Image(){}
    ~JPG() = default;
public:
    ImageType getImageType() override {
        return ImageType::JPG_image;
    }
    void print() override{
        std::cout << "This is a JPG file." << std::endl;
    }
};

class GIF : public Image{
public:
    ~GIF() = default;
    GIF() : Image(){}
public:
    ImageType getImageType() override {
        return ImageType::GIF_image;
    }
    void print() override{
        std::cout << "This is a GIF file." << std::endl;
    }
};

class FlyWeight{
public:
    FlyWeight() = default;
    ~FlyWeight() = default;

public:
    template <typename T>
    void addImage(const std::string name);
    void deleteImage(const std::string name);
    std::shared_ptr<Image> getImage(const std::string name);

private:
    std::unordered_map<std::string, std::shared_ptr<Image> > m_imageContainer;
};