/* functional: high. Draft verified against PAL assembly (state switch 0/1/2/3, scan args and stack args, effect calls, constants); 124 words differ in codegen only. */
typedef struct { s32 a,b,c; } Filter_00309708;
typedef struct { u8 pad0[0x6C]; f32 f6C; u8 pad70[0xF0-0x70]; } Weapon_00309708;
extern Filter_00309708 D_L01_001DC638;
extern Weapon_00309708 D_L01_002C5600[] __attribute__((section(".sdata")));
extern u8 D_001425D0[];
extern s32 D_L01_001DC630;
__asm__(".extern D_L01_001DC630, 4");
void func_L01_00309708(u8 *obj) {
    extern u8 *func_L01_00309D28(u8 *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_L01_00446760(Query_003090E0 *,u8 *,s32,vu0_v4 *,f32);
    extern void func_L01_00446978(u8 *,Query_003090E0 *);
    extern void func_L01_0031B090(u8 *,s32,s32);
    extern void func_L01_004501E8(void *,void *,f32,f32,s32 *,u8 **,s32,s32,f32,f32,f32,s32,Filter_00309708 *,s32,s32,s32);
    extern s32 func_L01_004C8258(u8 *,u8 *);
    extern void func_L01_004C81F0(u8 *,u8 *,s32);
    extern void func_L01_0030A3E8(u8 *,u8 *,s32);
    extern void func_003A52A0(s32,s32,u8 *);
    extern s32 func_0038CAD0(void *);
    extern f32 func_003824E0(f32,f32);
    extern u8 *func_L01_0046B458(void *,s32,f32,s32,f32,s32,s32,void *,f32,s32);
    extern void func_L01_004C7D98(void *,void *);
    extern void func_L01_0030BF20(void *,void *,s32,s32);
    extern void func_L01_004C8668(s32);
    extern void func_L01_004C8598(u8 *);
    extern void func_L01_00424D88(s32);
    extern void func_003C2880(u8 *);
    extern void func_L01_0030A670(u8 *);
    extern void func_L01_0030B670(u8 *);
    extern void func_L01_0030A198(u8 *);
    extern void func_L01_00404A10(void *,u8 *);
    Filter_00309708 filter=D_L01_001DC638;
    u8 *targets[15];
    vu0_v4 direction;
    Query_003090E0 query;
    s32 hit_count;
    u8 *state=*(u8 **)(obj+0x68);
    u8 *target;
    s32 i;
    u8 **hit;
    switch(obj[0x20]) {
    case 0: case 1:
        *(f32 *)(state+0x4C)+=(0.6f-*(f32 *)(state+0x4C))*0.125f;
        target=func_L01_00309D28(obj);
        if(target) {
            *(vu0_q *)&direction=*(vu0_q *)state;
            func_0038CF68(&direction,&direction,0.04000000283f);
            func_L01_00446760(&query,obj,0x410000,&direction,((Weapon_00309708 *)((s32)D_L01_002C5600+D_001425D0[0]*0xF0))->f6C);
            query.b18=1;query.b19=3;
            query.h1A=*(u16 *)(obj+0xAA);
            func_L01_00446978(target,&query);
            func_L01_0031B090(target,0xA0,*(s32 *)(obj+0xB8));
        }
        hit=targets;
        func_L01_004501E8(obj+0x10,obj+0xC0,6.283185482f,6.283185482f,&hit_count,hit,15,0,15.0f,0.0f,0.0f,0,&filter,1,-1,0);
        for(i=0;i<hit_count;i++,hit++) {
            if(*(s32 *)(state+0x54)<15 && func_L01_004C8258(obj,*hit)) {
                func_L01_004C81F0(obj,*hit,120);
                func_L01_0030A3E8(obj,*hit,10);
                func_003A52A0(0,0,obj);
            }
        }
        if(func_0038CAD0(state+0x34)) { obj[0x20]=2; *(s32 *)(state+0x34)=33; }
        break;
    case 2:
        func_L01_00309D28(obj);
        *(f32 *)(state+0x4C)=((f32)*(s32 *)(state+0x34)/40.0f)*0.59000003338f+0.01f;
        *(f32 *)(obj+0x10)+=func_003824E0(-0.1f,0.1f);
        *(f32 *)(obj+0x14)+=func_003824E0(-0.1f,0.1f);
        *(f32 *)(obj+0x18)+=func_003824E0(-0.1f,0.1f);
        qzero(&direction);
        func_L01_0046B458(obj+0x10,50,0.15f,0x4FFF0000,1.5f,0,2,&direction,0.002f,1);
        func_L01_0046B458(obj+0x10,50,0.125f,0x7FFFFFFF,1.25f,0,2,&direction,0.002f,1);
        if(func_0038CAD0(state+0x34)) obj[0x20]=3;
        break;
    case 3:
        if(*(s32 *)(state+0x54)==0 && *(s32 *)(state+0x58)==0) {
            func_L01_004C7D98(obj+0x10,&query);
            func_L01_0030BF20(obj+0x10,&query,6,0x72FF);
            func_L01_0030BF20(obj+0x10,&query,6,0xFF0000);
            func_L01_004C8668(*(s32 *)(state+0x50));
            func_L01_004C8598(obj);
            { s32 light=*(s32 *)(state+0x5C);
            D_L01_001DC630--;
            if(light!=-1) func_L01_00424D88(light); }
            func_003C2880(obj);
            return;
        }
        break;
    }
    func_L01_0030A670(obj);
    func_L01_0030B670(obj);
    func_L01_00404A10(func_L01_0030A198,obj);
}
