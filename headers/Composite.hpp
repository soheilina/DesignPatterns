/**
* @brief
    It implements the Composite Design Pattern music playlists.
    Main idea:  the Composite class aggerates objects of type Interface.
                So it can embody other objects of Composite class or of leaf class.
*/
#include <list>
#include <string>
#include <iostream>

#ifndef __COMPOSITE_HPP__
#define __COMPOSITE_HPP__

// Interface
class Playlist{
public:
    Playlist() = default;
    virtual ~Playlist() = default;
    Playlist(Playlist& rhs) = delete;
    Playlist(Playlist&& rhs) = delete;
    Playlist& operator=(Playlist& rhs) = delete;
    Playlist& operator=(Playlist&& rhs) = delete;

public:
    virtual void print() const = 0;
    virtual uint8_t getNumberOfTracks() const = 0;
    virtual std::string getName() const = 0;

protected:
    std::string m_name;
};

// Composite
class CompositePlaylist final : public Playlist{
public:
    CompositePlaylist(std::string name);
    ~CompositePlaylist() = default;
    CompositePlaylist(CompositePlaylist& rhs) = delete;
    CompositePlaylist(CompositePlaylist&& rhs) = delete;
    CompositePlaylist& operator=(CompositePlaylist& rhs) = delete;
    CompositePlaylist& operator=(CompositePlaylist&& rhs) = delete;

public:
    void add(Playlist* pl);
    void remove(Playlist* pl);
    void print() const override;
    uint8_t getNumberOfTracks() const override;
    std::string getName() const override;

private:
    /* Aggregation takes place here.
       The list aggerates Interface Pointers. By doing this we achieve two things:
       1) Object Slicing is prevented. 2) Base class pointer reaches virtual functions of Derived classes.
    */
   std::list<Playlist*> m_playlist;
    std::string m_name;
    };

// Leaf
class Track final : public Playlist{
public:
    Track(std::string name);
    ~Track() = default;
    Track(Track& rhs) = delete;
    Track(Track&& rhs) = delete;
    Track& operator=(Track& rhs) = delete;
    Track& operator=(Track&& rhs) = delete;

public:
    void print() const override;
    uint8_t getNumberOfTracks() const override;
    std::string getName() const override;
};
#endif /*#define __COMPOSITE_HPP__*/