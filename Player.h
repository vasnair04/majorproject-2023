#ifndef PLAYER_H
#define PLAYER_H
// class header for player class, class represents a player has attributes
// such as speed, number of targets and score
class Player { 
    private:
        int speed;
        int numTargets;
        // score is always initialised to 0
        int score;
    public:
        // default constructor sets all values to 0
        Player();
        // constructor sets speed and number of targets
        Player(int sped,int numTar);
        // set_ and get_ functions get and set certain values within the class
        void set_speed(int speedSet);
        void set_numTargets(int targetSet);
        void set_score(int scor);
        int get_speed();
        int get_numTargets();
        int get_score();
        
};

#endif