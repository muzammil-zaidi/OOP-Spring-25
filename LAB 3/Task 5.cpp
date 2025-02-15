#include<iostream>
#include<string>
using namespace std;

class MusicPlayer{
    private:
        string playlist[50];
        string currentlyPlayingSong;
        int songs;

    public:
        MusicPlayer(){
            songs=0;
            currentlyPlayingSong="";
        }

        void add(string name){
            if(songs<50){
                playlist[songs]=name;
                songs++;
                cout<<name<<" added to the playlist.\n";
            }
            else{
                cout<<"Playlist is full!\n";
            }
        }

        void remove_song(string name){
            int index=-1;
            for(int i=0;i<songs;i++){
                if(playlist[i]==name){
                    index=i;
                    break;
                }
            }
            if(index!=-1){
                for(int i=index;i<songs-1;i++){
                    playlist[i]=playlist[i+1];
                }
                songs--;
                cout<<name<<" removed from the playlist.\n";
                if(currentlyPlayingSong==name){ 
                    currentlyPlayingSong="Not found!";
                }
            }
            else{ 
                cout<<name<<"Not found!\n";
            }
        }

        void play(string name){
            bool found=false;
            for(int i=0;i<songs;i++){
                if(playlist[i]==name){
                    currentlyPlayingSong=name;
                    cout<<"Playing: "<<name<<"\n";
                    found=true;
                    break;
                }
            }
            if(!found){ 
                cout<<name<<"Not found!\n";
                }
        }

        void display(){
            if(songs==0){ 
                cout<<"Playlist is empty.\n";
            }
            else{
                cout<<"-------------------------------\n";
                cout<<"Playlist:\n";
                for(int i=0;i<songs;i++){
                    cout<<playlist[i]<<"\n";
                }
                cout<<"-------------------------------\n";
            }
        }
};

int main(){
    MusicPlayer m;
    m.add("Hall of Fame");
    m.add("Snowman");
    m.display();
    m.play("Snowman");
    m.remove_song("Snowman");
    m.display();
    
    return 0;
}
