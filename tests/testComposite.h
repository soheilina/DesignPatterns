void testComposite(){
    std::cout << "----- TEST STRATS-----" << std::endl;
    
    
    // Add 3 tracks of Adele to a composite named "Adele"
    Track t1("track_01");
    Track t2("track_02");
    Track t3("track_03");
    CompositePlaylist Adele("Adele");
    Adele.add(&t1);
    Adele.add(&t2);
    Adele.add(&t3);
    std::cout << std::to_string(Adele.getNumberOfTracks()) << " track added to the playlist named " << Adele.getName() << std::endl;

    // Add 2 tracks of Beatles
    Track t4("track_04");
    Track t5("track_05");
    CompositePlaylist Beatles("Beatles");
    Beatles.add(&t4);
    Beatles.add(&t5);
    std::cout << std::to_string(Beatles.getNumberOfTracks()) << " track added to the playlist named " << Beatles.getName() << std::endl;

    // Add a single Track of Ray Charles
    Track t6("RayCharles");

    // Make a composite of all of them
    CompositePlaylist myMusic("myMusic");
    myMusic.add(&Adele);
    myMusic.add(&Beatles);
    myMusic.add(&t6);
    std::cout << "Two playlists named Adele and Beatles along with a track by Ray Charles added to " << myMusic.getName() << std::endl;
    std::cout << std::endl;
    
    // remove one track from Adele, one track from Beatles, and the track by RayCharles from MyMusic
    Adele.remove(&t3);
    Beatles.remove(&t4);
    myMusic.remove(&t6);
    
    myMusic.print();
}