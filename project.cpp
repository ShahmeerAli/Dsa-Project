#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

//---------------------------------------//IMPLEMENTED BY WAMIQ//------------------------------------------
struct SongNode {
    string name;
    string artist;

    SongNode(const string& songName, const string& artistName) : name(songName), artist(artistName) {}
};
struct ArtistTreeNode {
    string artistName;
    SongNode* song;
    ArtistTreeNode* left;
    ArtistTreeNode* right;

    ArtistTreeNode(const string& name, SongNode* song) : artistName(name), song(song), left(nullptr), right(nullptr) {}
};

struct ArtistLLNode {
    ArtistTreeNode* artistName;
    ArtistLLNode* next;

    ArtistLLNode(ArtistTreeNode* value) : artistName(value), next(nullptr) {}
};

class ArtistTree {
private:
    ArtistTreeNode* root;

    ArtistTreeNode* insertNode(ArtistTreeNode* root, SongNode* song) {
        if (root == nullptr) {
            return new ArtistTreeNode(song->artist, song);
        }

        if (song->name < root->song->name) {
            root->left = insertNode(root->left, song);
        } else {
            root->right = insertNode(root->right, song);
        }

        return root;
    }

    bool searchNode(ArtistTreeNode* root, const string& value) {
        if (root == nullptr) {
            return false;
        }

        if (root->song->name == value) {
            return true;
        } else if (value < root->song->name) {
            return searchNode(root->left, value);
        } else {
            return searchNode(root->right, value);
        }
    }

    void inorderTraversal(ArtistTreeNode* root,int count) {
        if(count==0){
            cout << root->artistName << " \n";
        }
        if (root != nullptr) {
            count++;
            inorderTraversal(root->left,count);
            cout << root->song->name << " ";
            inorderTraversal(root->right,count);
        }else if(root==nullptr&&count==0){
            cout << "No Songs FounD"<<endl;
        }
    }

public:
    ArtistTree() : root(nullptr) {}

    void insert(SongNode* song) {
        root = insertNode(root, song);
    }

    bool search(SongNode* song) {
        return searchNode(root, song->name);
    }

    void inorder() {
        inorderTraversal(root, 0);
        cout << endl;
    }
};

class ArtistLL {
private:
    ArtistLLNode* head = nullptr;

    string toLower(const string& str) {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }

    bool artistExists(const string& artistName) {
        ArtistLLNode* current = head;
        string lowerArtistName = toLower(artistName);
        while (current) {
            if (toLower(current->artistName->artistName) == lowerArtistName) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

public:
    ArtistLL() : head(nullptr) {}

    void insertArtist(ArtistTreeNode* artist) {
        if (artistExists(artist->artistName)) {
            cout << "Artist \"" << artist->artistName << "\" already exists in the list." << endl;
            return;
        }

        ArtistLLNode* newNode = new ArtistLLNode(artist);
        if (!head) {
            head = newNode;
        } else {
            ArtistLLNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteArtist(const string& artistName) {
        if (!head) return;

        if (toLower(head->artistName->artistName) == toLower(artistName)) {
            ArtistLLNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ArtistLLNode* current = head;
        while (current->next && toLower(current->next->artistName->artistName) != toLower(artistName)) {
            current = current->next;
        }

        if (current->next) {
            ArtistLLNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void display() {
        ArtistLLNode* current = head;
        while (current) {
            cout << current->artistName->artistName << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

//-------------------------------------------//IMPLEMENTED BY SHAHMEER//------------------------------------------
class TimeFrame{
  private : int seconds;
  private : int minutes;

  public:
    TimeFrame() : seconds(0), minutes(0) {}

    TimeFrame(int sec, int mint) : seconds(sec), minutes(mint) {}

  

    void displayDuration(){
      cout<<"Duration "<<minutes<<" m "<<seconds<<" s";
    }
  
};

class Date{
  private : int releaseDate;

   public:
   Date():releaseDate(0) {}


   Date(int date):releaseDate(date){}

  
   void  displayDate(){
    cout<<releaseDate;
  }


};

class Song{
  private : TimeFrame playtime;
  private : Date date;

  public:  struct song{
    TimeFrame playtime;
     Date date;
     string name;
     string writer;
     song * next;
     song * previous;
    }*head,*tail;


public:
    Song(){
       head=nullptr;
       tail=nullptr;
        
    }


   void addSong(string data,string writer,TimeFrame time,Date d){
     
     song *newSong=new song;
     newSong->name=data;
     newSong->playtime=time;
     newSong->date=d;
     newSong->writer=writer;
    

     if(head==nullptr){
        head=newSong;
        newSong->next=nullptr;
        newSong->previous=head;
        tail=newSong;
        
     }

     song *temp=head;

     while(temp->next!=nullptr){
        temp=temp->next;
     }

     newSong->previous=temp;
     temp->next=newSong;
     tail=newSong;
     newSong->next=nullptr;
     cout<<"SONG ADDED SUCCESSFULLY"<<endl;



   }


   bool SearchSong(string name){
       song * temp=head;
       while(temp!=nullptr){
        if(temp->name==name){
            cout<<"SONG FOUND"<<endl;
            cout<<temp->name<<" By:  "<<temp->writer;
            return true ;
        }else{
               temp=temp->next;
            }


      }

       cout<<"SONG NOT FOUND"<<endl;
       
    
    }
 

   void display(){
      song *temp=head;
      int count=1;
      while(temp!=nullptr){
        cout<<count<<"."<<" "<<temp->name<<" Singer: "<<temp->writer<<": ";
        temp->playtime.displayDuration(); 
        cout<<endl;
        temp=temp->next;
        count++;
      }
      
   }

   
void selectionSort(stack<song*>& st){
        vector <song*> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        int n = temp.size();
        for(int i = 0; i < n - 1; ++i){
            int minIndex = i;
            for(int j = i + 1; j < n; ++j){
                if(temp[j]->name < temp[minIndex]->name){
                    minIndex = j;
                }
            }
            swap(temp[i], temp[minIndex]);
        }

        for(int i = n - 1; i >= 0; --i){
            st.push(temp[i]);
        }
  }

  void songPlay(stack<Song::song*>& st, queue<Song::song*>& queue, string name){
    bool play = false;
    stack<song*> tempStack = st;

    while (!tempStack.empty()) {
        Song::song* current = tempStack.top();
        tempStack.pop();
        if (current->name == name) {
            play = true;
            cout << "Playing song: " << name << endl;
            queue.push(current);
            break;
        }
    }

    if (!play) {
        cout << "Song not found" << endl;
    }
}



 void displayQueue(queue<song*>&que){
    if(que.empty()){
      return;
    }
    int count=1;
    while(!que.empty()){
      Song::song* curr=que.front();
      que.pop();
      cout<<"History : "<<count<<":"<<curr->name<<"By: "<<curr->writer<<" "; 
      cout<<endl;
    }
  }

 
//------------------------------------------------IMPLEMENTED BY SOBAN-----------------------------------------
   void playList(string name,stack<song*>& st){
     song * temp=head;
     while(temp!=nullptr){
      if(temp->name==name){
        st.push(temp);
        cout<<"Song Added to the PlayList"<<endl;
        return;
      }else{
        temp=temp->next;
      }
     }


      
    
    }

    void displayPlaylist(stack<song*> &st){
      if(st.empty()){
        cout<<"No Song Found"<<endl;
        return;
      }

        stack<Song::song*> tempStack = st; 
        while (!tempStack.empty()) {
          Song::song* current = tempStack.top();
          tempStack.pop();
          cout << current->name << " By: " << current->writer << ": ";
          current->playtime.displayDuration();
          cout << endl;
        }
    }


 void deleteSong(string name,stack<song*>&st){
  stack<song*> stack;
  while(!st.empty()){
    if(st.top()->name!=name){
       stack.push(st.top());
       
    }
    st.pop();
  }

  

  while(!stack.empty()){
    st.push(stack.top());
    stack.pop();
  }

  cout << "Song : " << name << " deleted from the playlist." << endl;
 }

 
  
  



};




int main(){

   Song songs;
   ArtistTree artistTree;
   ArtistLL artistList;
   stack<Song::song*> stack;
   queue<Song::song*> que;
   int option;
  
   cout<<"--------------------------TUNE FUSION----------------------------------"<<endl;
   do{
      cout<<"1.Add Song"<<endl;
      cout<<"2.Search a Song"<<endl;
      cout<<"3.All Songs"<<endl;
      cout<<"4.Create PlayList"<<endl;
      cout<<"5.Delete Song"<<endl;
      cout<<"6.Display PlayList"<<endl;
      cout<<"7.Sort PlayList"<<endl;
      cout<<"8.Play Songs"<<endl;
      cout<<"9.Playing History"<<endl;
      cout<<"10.Artists in Sorted Order"<<endl;
      cout<<"0.Exit"<<endl;
      cin>>option;
      string name,singer;
      int minutes,seconds,date;
      
     
        if(option==1)
        {
          cout<<"Enter the Song's Name"<<endl;
          cin>>name;
          cout<<"Enter the Singer"<<endl;
          cin>>singer;
          cout<<"Enter the Releasing Date of the Song"<<endl;
          cin>>date;
          cout<<"Enter the Duration of the Song"<<endl;
          cout<<"(EX.DURATION: MINUTES SECONDS)"<<endl;
          cin>>minutes>>seconds;
          TimeFrame duration(minutes,seconds);
          Date datee(date);
          songs.addSong(name,singer,duration,date);
          SongNode* song = new SongNode(name,singer);
          artistTree.insert(song);
          cout<<endl;
        }

        else if(option==2){
          cout<<"Search the Song"<<endl;
          string name; 
          cin>>name;
          songs.SearchSong(name);  
          cout<<endl;
        }
        else if(option==3){
          cout<<"All Songs"<<endl;
          songs.display();
          cout<<endl;
        }
        else if(option==4){
          
           cout<<"Select Songs to add in Playlist"<<endl;
           songs.display();
           cout<<"Enter the name of the Song "<<endl;
           string songname;
           cin>>songname;
           songs.playList(songname,stack);
           cout<<endl;
           
        }else if(option==5){
          cout<<"Song's Name"<<endl;
          string sname;
          cin>>sname;
          songs.deleteSong(sname,stack);
          cout<<endl;

        }else if(option==6){
          cout<<"Play List : "<<endl;
          songs.displayPlaylist(stack);
          cout<<endl;
        }else if(option==7){
          cout<<"Sorting Songs"<<endl;
          songs.selectionSort(stack);
          cout<<"Songs Sorted"<<endl;
          cout<<endl;

        }else if(option==8){
          songs.displayPlaylist(stack);
          cout<<"Select song you want to play"<<endl;
          string songname;
          cin>>songname;
          songs.songPlay(stack ,que,songname);
          cout<<endl;


        }else if(option==9){
          songs.displayQueue(que);
          cout<<endl;
        }else if(option==10){
          artistTree.inorder();
          artistList.display();
          cout<<endl;
        }
        else if(option==11){
          cout<<"Name the artist to delete"<<endl;
          string s;
          cin>>s;
          artistList.deleteArtist(s);
          artistList.display();
        }else{
          cout<<"Please Enter the correct option"<<endl;
        }
    }while(option!=0);



    return 0;
}