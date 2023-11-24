/*class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        history.push_back(t);

        int count = 0;
        for(int i=0;i<history.size();i++){
            if(t - history[i] <= timeout_time)
                return history.size()-i;
        }
        return count;
    }
private:
    std::vector<int> history;
    const int timeout_time = 3000;
};*/

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        requests.push(t);

        while (!requests.empty() && requests.front() < t - timeout_time) {
            requests.pop();
        }
        return requests.size();
    }
private:
    std::queue<int> requests;
    const int timeout_time = 3000;
};
