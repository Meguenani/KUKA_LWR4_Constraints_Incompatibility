double absolute(double var){
double absolute_val;

if(var < 0){
absolute_val = -var;
}

if(var > 0){
absolute_val = var;
}

if(var == 0){
absolute_val = 0;
}

return absolute_val;
}




double positive_definit(double var){
double positive_val;

if(var < 0){
positive_val = 0;
}

if(var >= 0){
positive_val = var;
}

return positive_val;
}
