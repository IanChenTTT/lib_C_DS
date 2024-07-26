typedef struct{
    short int vert;
    short int horiz;
}  offset;
offset move[8]; /* array of each direction*/
void OffsetInitialize(){
    move[0].vert = -1;
    move[0].horiz = 0;
    move[1].vert = -1;
    move[0].horiz = 1;
    move[2].vert = 0;
    move[2].horiz = 1;
    move[3].vert = 1;
    move[3].horiz = 1;
    move[4].vert = 1;
    move[4].horiz = 0;
    move[5].vert = 1;
    move[5].horiz = -1;
    move[6].vert = 0;
    move[6].horiz = -1;
    move[7].vert = -1;
    move[7].horiz = -1;
}
int main(){

}                
