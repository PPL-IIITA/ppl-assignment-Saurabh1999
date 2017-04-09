#include "boy.h"
#include "girl.h"

bool boy::check_dating_req (boy b,girl g){
    
    
    return (b.budget >= g.mnt_budget && b.min_attraction_req <= g.attractiveness ? true : false);

}


