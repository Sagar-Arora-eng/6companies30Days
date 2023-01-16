class StockPrice {
     unordered_map<int, int> stock; 
     multiset<int> s; 
     int latest_time = 0; 
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
       if(stock.count(timestamp)){
         auto it = s.find(stock[timestamp]); 
         s.erase(it); 
       }
       stock[timestamp] = price; 
       s.insert(price); 
       latest_time = max(latest_time, timestamp); 
    }
    
    int current() {
        return stock[latest_time]; 
    }
    
    int maximum() {
        return *s.rbegin(); 
    }
    
    int minimum() {
        return *s.begin(); 
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */