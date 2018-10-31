#include<iostream>
#include<string>
#include<utility>
#include<list>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
class LRUCache {
public:
   
    
    LRUCache(int _capacity):capacity(_capacity),cur_capacity(0) {
        
    }
    
    int get(int key) {
        map<int,int>::iterator it=imp.find(key);
    
        if(imp.begin()!=imp.end() && it!=imp.end())
        {
            return it->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        map<int,int>::iterator it=imp.find(key);
        if(it==imp.end()) 
        {
            imp.insert(make_pair(key,value));
            ilt.push_front(value);
            cur_capacity++;
        }
        else  //ÔÚ»º´æÖÐ
        {
            if(cur_capacity!=capacity)
            {
                list<int>::iterator it=find(ilt.begin(),ilt.end(),value);
                int tmp=*it;
                ilt.erase(it);
                ilt.push_front(tmp);
            }
            else
            {
                cur_capacity--;
                int temp=ilt.back();
                for(map<int,int>::iterator i=imp.begin();i!=imp.end();++i)
                {
                    if(i->second==temp)
                    {
                        key=i->first;
                    }
                }
                
                map<int,int>::iterator it=imp.find(key);
                imp.erase(it);
                ilt.pop_back();
            }
        }
    }
    private:
    int capacity;
    int cur_capacity;
    map<int,int> imp;
    list<int> ilt;
};
*/
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        const auto it = m_.find(key);
        // If key does not exist
        if (it == m_.cend()) return -1;
 
        // Move this key to the front of the cache
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {        
        const auto it = m_.find(key);
        
        // Key already exists
        if (it != m_.cend()) {
            // Update the value
            it->second->second = value;
            // Move this entry to the front of the cache
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        
        // Reached the capacity, remove the oldest entry
        if (cache_.size() == capacity_) {
            const auto& node = cache_.back();
            m_.erase(node.first);
            cache_.pop_back();
        }
        
        // Insert the entry to the front of the cache and update mapping.
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }
private:
    int capacity_;
    list<pair<int,int>> cache_;
    unordered_map<int, list<pair<int,int>>::iterator> m_;
};
 
int main()
{
	list<int> ilt;
	for(auto i=0;i<10;i++)
	{
		ilt.push_back(i); 
	} 
	int val=4;
	auto it=find(ilt.begin(),ilt.end(),end);
	ilt.splice(ilt.begin(),ilt,it);
	for(auto i:ilt)
	{
		cout<<i<<endl;
	}
}
