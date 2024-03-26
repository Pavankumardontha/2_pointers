bool isRefillmentRequired(int current_capacity , int plant)
{
    if(current_capacity >= plant)
    return false;
    return true;
}

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) 
    {
        int steps=0;
        int current_capacity=capacity;
        for(int i=0;i<plants.size();i++)
        {
            /*
            is refillment required ??
            a) yes - add backward steps and forward steps and move forward
            b) no - add one step and move forward
            */
            if(isRefillmentRequired(current_capacity, plants[i]))
            {
                current_capacity = capacity;
                int backend_steps = i;
                int forward_steps = i+1;
                steps = steps + backend_steps + forward_steps;
            }
            else
            steps = steps + 1;
            current_capacity = current_capacity - plants[i];
        }
        return steps;   
    }
};
