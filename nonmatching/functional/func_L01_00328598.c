/* functional: medium. 140 words differ (VU asm scheduling, saved registers); same sequence of calls and arithmetic. */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00328598;
extern u8 D_001D5477;
extern f32 D_L01_001DC0E8,D_L01_001DC0EC;
extern f32 D_L01_001DCA34;
__asm__(".extern D_L01_001DCA34, 4");
extern f32 D_L01_001DCA38;
__asm__(".extern D_L01_001DCA38, 4");
extern f32 D_L01_001DCA44;
__asm__(".extern D_L01_001DCA44, 4");
extern f32 D_L01_001DCA48;
__asm__(".extern D_L01_001DCA48, 4");
extern f32 D_L01_001DCA4C;
__asm__(".extern D_L01_001DCA4C, 4");
extern f32 D_L01_001DCA50;
__asm__(".extern D_L01_001DCA50, 4");
extern f32 D_L01_001DCA54;
__asm__(".extern D_L01_001DCA54, 4");
extern f32 D_L01_001DCA58;
__asm__(".extern D_L01_001DCA58, 4");
extern f32 D_L01_001DCA5C;
__asm__(".extern D_L01_001DCA5C, 4");
extern f32 D_L01_001DCA60;
__asm__(".extern D_L01_001DCA60, 4");
extern f32 D_L01_001DCA64;
__asm__(".extern D_L01_001DCA64, 4");
extern f32 D_L01_001DCA68;
__asm__(".extern D_L01_001DCA68, 4");
extern s32 D_L01_001DCA80;
__asm__(".extern D_L01_001DCA80, 4");
__asm__(".extern D_L01_001DCA88, 0");
extern s32 D_L01_001DCA88[] __attribute__((section(".sdata")));
void func_L01_00328598(u8 *obj,s32 kind,V_00328598 *axis,void *matrix,long arg) {
    extern u8 *func_00382348(void *);
    extern f32 func_0038CE68(void *,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038D000(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038B4D0(s32,s32,s32,s32,s32,s32,s32,s32,long,long);
    V_00328598 delta,projection,screen;
    V_00328598 *d;
    u8 *info;
    f32 size=D_L01_001DCA5C;
    f32 amount,distance,reciprocal;
    info=func_00382348(obj);
    if(info) {
        switch(info[8]) {
        case 0:size=D_L01_001DCA58;break;
        case 2:size=D_L01_001DCA60;break;
        case 3:size=D_L01_001DCA64;break;
        }
    }
    if(kind==3)size+=D_L01_001DCA68;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(*(V_00328598 *)(obj+0x10)), "m"(*(V_00328598 *)D_001A4C60) : "vf1","vf2");
    d=&delta;
    amount=func_0038CE68(d,axis);
    func_0038CE20(&projection,axis,amount);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(delta),"m"(projection) : "vf1","vf2");
    distance=func_0038CEA8(d);
    if(distance>D_L01_001DCA44)distance=D_L01_001DCA44;
    else if(distance<D_L01_001DCA48)distance=D_L01_001DCA48;
    reciprocal=1.0f/D_L01_001DCA44;
    amount=distance*reciprocal;
    func_0038D000(&delta,&delta,matrix);
    func_0038CF68(&screen,&delta,amount*D_L01_001DCA54);
    if(D_001D5477)screen.x=-screen.x;
    screen.x=screen.x*D_L01_001DCA4C+D_L01_001DCA34-size;
    screen.y=screen.y*D_L01_001DCA50+D_L01_001DCA38-size;
    func_0038B4D0((s32)(screen.x*D_L01_001DC0E8),(s32)(screen.y*D_L01_001DC0EC),(s32)((size+size)*D_L01_001DC0E8),(s32)((size+size)*D_L01_001DC0EC),0,0,D_L01_001DCA80,D_L01_001DCA80,(long)D_L01_001DCA88[kind],arg);
}
