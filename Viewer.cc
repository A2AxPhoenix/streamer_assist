#include "Viewer.h"
using namespace std;
using V = Viewer; // Typing sucks sometimes

V::Viewer() { // Default Constructor
	ID = 0;
	gamertag = "Placeholder";
	age = 16; // Must be 16 years or older to participate
	preferredContact = "email";
	hasParticipated = false;
	entries = 0;
}
V::Viewer(long long newID, string newGT, int newAge) {  // Creating a new Viewer? Use this to construct one. GT = gamertag
	ID = newID;
	gamertag = newGT;
	age = newAge;
	preferredContact = "email";
	hasParticipated = false;
	entries = 0;
}
		// My plethora of methods
		long long V::get_ID() const { return ID; }
		string V::get_gamertag() const { return gamertag; }
		int V::get_age() const { return age; }
		string V::get_twitterHandle() const { return twitterHandle; }
		string V::get_twitchUsername() const { return twitchUsername; }
		string V::get_discordName() const { return discordName; }
		string V::get_instagramName() const { return instagramName; }
		string V::get_snapchatID() const { return snapchatID; }
		string V::get_email() const { return email; }
		string V::get_defaultSocialMedia() const { return defaultSocialMedia; }
		string V::get_preferredContact() const { return preferredContact; };
		bool V::get_didFollowTwitch() const { return didFollowTwitch; }
		bool V::get_didFollowTwitter() const { return didFollowTwitter; }
		bool V::get_didFollowInstagram() const { return didFollowInstagram; }
		bool V::get_didFollowSnapchat() const { return didFollowSnapchat; }
		bool V::get_didJoinDiscord() const { return didJoinDiscord; }
		bool V::get_hasParticipated() const { return hasParticipated; }
		int V::get_totalFollows() const { return totalFollows; }
		int V::get_entries() const { return entries; }
		void V::set_ID(long long newID) { ID = newID; }
		void V::set_gamertag(string newGT) { gamertag = newGT; } // GT = gamertag
		void V::set_age(int newAge) { age = newAge; }
		void V::set_twitterHandle(string newTwitterHandle) { twitterHandle = newTwitterHandle; }
		void V::set_twitchUsername(string newTwitchUsername) { twitchUsername = newTwitchUsername; }
		void V::set_discordName(string newDiscordName) { discordName = newDiscordName; }
		void V::set_instagramName(string newInstagramName) { instagramName = newInstagramName; }
		void V::set_snapchatID(string newSnapchatID) { snapchatID = newSnapchatID; }
		void V::set_email(string newEmail) { email = newEmail; }
		void V::set_defaultSocialMedia(string newDefault) { defaultSocialMedia = newDefault; }
		void V::set_preferredContact(string newPreferredContact) { preferredContact = newPreferredContact; }
		void V::set_didFollowTwitch(bool followedTwitch) { didFollowTwitch = followedTwitch; }
		void V::set_didFollowTwitter(bool followedTwitter) { didFollowTwitter = followedTwitter; }
		void V::set_didFollowInstagram(bool followedInstagram) { didFollowInstagram = followedInstagram; }
		void V::set_didFollowSnapchat(bool followedSnapchat) { didFollowSnapchat = followedSnapchat; }
		void V::set_didJoinDiscord(bool joinedDiscord) { didJoinDiscord = joinedDiscord; }
		void V::set_didParticipate(bool participated) { hasParticipated = participated; }
		void V::set_totalFollows(int newFollows) { totalFollows = newFollows; }
		void V::set_entries(int newEntries) { entries = newEntries; }
		// Overloaded Operators
		bool V::operator<(const Viewer &v) const {
			return ID < v.ID;
		}
		bool V::operator==(const Viewer &v) const {
			if (gamertag == v.gamertag) {
				return true;
			}
			else return false;
		}
		ostream& operator<<(ostream& outs, const Viewer &v) {
			outs << "Outputting Viewer... " << endl; 
			outs << "ID: " << v.ID << endl;
			outs << "Gamertag: " << v.gamertag << endl;
			outs << "Age: " << v.age << endl;
			outs << "Preferred Contact: " << v.preferredContact << endl;
			outs << "Entries: " << v.entries << endl;
			return outs;
		}
		istream& operator>>(istream& ins, Viewer &v) {
			ins >> v.ID >> v.gamertag >> v.age >> v.preferredContact;
			return ins;
		}
