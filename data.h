#include <cmath>

class Data
{
    private:
        int weighted_val;
        int unweighted_val;
    
    public:
        static int comparison_count;

        Data()
        {
            weighted_val = 0;
            unweighted_val = 0;
        }

        Data(int unweighted_val)
        {
            this->unweighted_val = unweighted_val;
            this->weighted_val = weight(unweighted_val);
        }

        static int weight(int x) 
        { 
            return int( x*x + (std::sqrt(x) + 4*x)*(1+std::sin(x)) ) % 23; 
        }

        bool operator<(const Data & other) const
        {
            ++comparison_count; 
            
            if (weighted_val < other.weighted_val)
            {
                return true;
            }

            else if (weighted_val > other.weighted_val)
            {
                return false;
            }

            else
            {
                return unweighted_val < other.unweighted_val;
            }
        }

    int getUnweighted() const
    {
        return unweighted_val;
    }
    
};

int Data::comparison_count = 0;

