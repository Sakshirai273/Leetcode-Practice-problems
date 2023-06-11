class SnapshotArray {
private:
    int snapid=0;
    vector<map<int,int>> arr;
public:
    SnapshotArray(int length) {
        arr.resize(length);
        for(int i=0;i<length;i++){
            arr[i][0]=0;
        }
    }
    
    void set(int index, int val) {
        arr[index][snapid]=val;
    }
    
    int snap() {
        snapid++;
        return snapid-1;
    }
    
    int get(int index, int snap_id) {
        auto it=arr[index].upper_bound(snap_id);
        it--;
        return (*it).second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */