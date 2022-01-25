#ifndef VIEWER_H
#define VIEWER_H
#include <iostream>
#include <stdexcept> // TODO: HANDLE EXCEPTIONS IN Set Methods and Constructors
using namespace std;

class Viewer {
	private:
		long long ID; // Unique ID will be assigned in constructor...sort on this!
		string gamertag; // Part of Default Constructor
		int age; // Part of Default Constructor
		string twitterHandle; // For these and below they have to have at least one!
		string twitchUsername;
		string discordName;
		string instagramName;
		string snapchatID;
		string email;
		// Viewer must have at least one social media. If only one, set this and the corresponding 
		// social media above. If they have more than one, set defaultSocialMedia to their Preferred Contact.
		string defaultSocialMedia;
		string preferredContact; // PARTICIPANT MUST HAVE!!!!!
		bool didFollowTwitch; // 1 entry per one of these if true.
		bool didFollowTwitter;
		bool didFollowInstagram;
		bool didFollowSnapchat;
		bool didJoinDiscord;
		bool hasParticipated; // Have they participated in the raffle before?
		// Essentially, calculate how many of bools are true (except hasParticipated), then set this to the amount they followed.
		int totalFollows; 
		int entries; // Part of Default Constrctor...How we tell how many entries a specific viewer has.
	public:
		Viewer(); // Default Constructor
		Viewer(long long newID, string newGT, int newAge); // Creating a new Viewer? Use this to construct one. GT = gamertag
		// My plethora of methods
		long long get_ID() const;
		string get_gamertag() const;
		int get_age() const;
		string get_twitterHandle() const;
		string get_twitchUsername() const;
		string get_discordName() const;
		string get_instagramName() const;
		string get_snapchatID() const;
		string get_email() const;
		string get_defaultSocialMedia() const;
		string get_preferredContact() const;
		bool get_didFollowTwitch() const;
		bool get_didFollowTwitter() const;
		bool get_didFollowInstagram() const;
		bool get_didFollowSnapchat() const;
		bool get_didJoinDiscord() const;
		bool get_hasParticipated() const;
		int get_totalFollows() const;
		int get_entries() const;
		void set_ID(long long newID);
		void set_gamertag(string newGT);
		void set_age(int newAge);
		void set_twitterHandle(string newTwitterHandle);
		void set_twitchUsername(string newTwitchUsername);
		void set_discordName(string newDiscordName);
		void set_instagramName(string newInstagramName);
		void set_snapchatID(string newSnapcharID);
		void set_email(string newEmail);
		void set_defaultSocialMedia(string newDefault);
		void set_preferredContact(string newPreferredContact);
		void set_didFollowTwitch(bool followedTwitch);
		void set_didFollowTwitter(bool followedTwitter);
		void set_didFollowInstagram(bool followedInstagram);
		void set_didFollowSnapchat(bool followedSnapchat);
		void set_didJoinDiscord(bool joinedDiscord);
		void set_didParticipate(bool participated);
		void set_totalFollows(int newFollows);
		void set_entries(int newEntries);
		// Overloaded Operators
		bool operator<(const Viewer &v) const;
		bool operator==(const Viewer &v) const;
		friend ostream& operator<<(ostream& outs, const Viewer &v);
		friend istream& operator>>(istream& ins, Viewer &v);
}; 
#endif
