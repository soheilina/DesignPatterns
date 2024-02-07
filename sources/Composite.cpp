#include "../headers/Composite.hpp"

//============================================================
//-- Class CompositePlaylist
//============================================================
CompositePlaylist ::CompositePlaylist(std::string name)
    : m_playlist(), m_name(name)
{
}

void CompositePlaylist ::add(Playlist *pl)
{
    m_playlist.push_back(pl);
}

void CompositePlaylist ::remove(Playlist *pl)
{
    auto it = std::find_if(m_playlist.begin(), m_playlist.end(), [&](auto &it)
                           { return (it->getName() == pl->getName()); });
    m_playlist.erase(it);
}

void CompositePlaylist ::print() const
{
    uint8_t numberOfTracks{0};
    std::string begining{""};
    for (auto &i : m_playlist)
        numberOfTracks += i->getNumberOfTracks();

    if (numberOfTracks == 0)
    {
        begining = "There is no track ";
    }
    else if (numberOfTracks == 1)
    {
        begining = "There is 1 track ";
    }
    else
    {
        begining = "There are " + std::to_string(numberOfTracks) + "tracks ";
    }
    std::cout << begining << "in the playlist named " << m_name << ":" << std::endl;

    for (auto &i : m_playlist)
    {
        i->print();
    }
}

uint8_t CompositePlaylist::getNumberOfTracks() const
{
    return m_playlist.size();
}

std::string CompositePlaylist ::getName() const
{
    return m_name;
}
//============================================================
//-- Class Track
//============================================================
Track ::Track(std::string name)
{
    m_name = name;
}

void Track ::print() const
{
    std::cout << m_name << std::endl;
}

uint8_t Track ::getNumberOfTracks() const
{
    return 1;
}

std::string Track ::getName() const
{
    return m_name;
}
