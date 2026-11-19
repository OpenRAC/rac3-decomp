/* functional: high. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 2-word difference (v0 vs v1 register for one addiu/store); 30 diff with the file flags in my check; not byte-identical, behaviour as retail. */
typedef struct {
 u8 pad0[0x1210]; s32 fireButton;
 u8 pad1214[0x1220-0x1214]; s32 handTicks;
 u8 pad1224[0x1430-0x1224]; u8 *target;
 u8 pad1434[0x25C4-0x1434]; s32 state;
 u8 pad25C8[0x25E9-0x25C8]; u8 firing;
 u8 pad25EA[3]; u8 noFiring;
 u8 pad25EE[0x28BC-0x25EE]; s32 aimingWait;
} Game_0031CCE8;
typedef struct {
 u8 pad0; u8 level; u8 pad2[0x50-2]; f32 cooldown; u8 pad54[0xF0-0x54];
} Weapon_0031CCE8;
extern Game_0031CCE8 D_001A4BE0;
extern u8 D_001425C0[],D_00142A60[];
extern G_31DB28 D_L01_002C5600[];
extern s32 D_L01_001E1790;
extern s32 D_L01_001D6694;
extern u8 *D_001D52FC;
extern u8 D_L01_002AE840[];
void func_L01_0031CCE8(u8 *object) {
    extern s32 func_0038CAD0(s32);
    extern void func_L01_005003D0(s32,s32);
    extern void func_L01_00444F38(u8 *,s32,s32,s32,s32);
    extern void func_L01_0031D188(u8 *,void *);
    extern f32 *func_00382348(void *);
    extern void func_L01_004C7438(void *,void *,void *,s32,f32,f32,f32,f32);
    extern s32 func_L01_004C7A18(void *,void *,void *,void *,void *,void *,void *,f32);
    extern void func_L01_0040E050(void *);
    extern s32 func_L01_005119E0(s32);
    extern void func_003A52A0(s32,s32,u8 *);
    extern void func_L01_004EAA80(void);
    extern void func_L01_005118D0(s32,s32);
    extern void func_L01_0031D218(u8 *,u8 *,u8 *);
    extern void func_L01_0031D1D8(u8 *,s32,s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *,s32);
    extern void func_L01_003F2278(s32,s32);
    extern void func_L01_00404A10(void *,u8 *);
    extern void func_L01_0031D398(u8 *);
    f32 position[4] __attribute__((aligned(16)));
    f32 velocity[4] __attribute__((aligned(16)));
    u8 *s=*(u8 **)(object+0x68);
    u8 *target;
    f32 *health;
    s32 allowed;
    s32 hadTimer;
    if(!object[0x20]) {
        object[0x20]=1;
        *(s32 *)(s+0x28)=-1;
        *(s32 *)(s+0x20)=0;
        *(s32 *)(s+0x2C)=0;
        D_L01_001E1790=17;
    }
    if(D_001A4BE0.state==1) func_L01_005003D0(29,1);
    if(((Weapon_0031CCE8 *)D_L01_002C5600)[D_001425C0[0x13]].level>=2) D_00142A60[0x13]|=0x20;
    if(object[0x42]==object[0x43] && (object[0x60]&2)) func_L01_00444F38(object,1,0,2,0);
    func_L01_0031D188(object,position);
    target=0;
    if(D_001A4BE0.target && (D_001A4BE0.target)[0x20]!=0xFE && (D_001A4BE0.target)[0x20]!=0xFD) {
        health=func_00382348(D_001A4BE0.target);
        if(health && *health>0.0f) target=D_001A4BE0.target;
    }
    allowed=1;
    if(D_001A4BE0.state==29) {
        if(!func_0038CAD0((s32)&D_001A4BE0.aimingWait)) allowed=0;
    } else D_001A4BE0.aimingWait=33;
    func_L01_004C7438(velocity,position,target,0,1.6f,10.0f,0.3f,0.0058400002f);
    *(s32 *)(s+0x24)=func_L01_004C7A18(position,velocity,s,s+0x10,object,0,0,0.0058400002f);
    hadTimer=1;
    if(*(f32 *)(s+0x20)<=0.0f) hadTimer=0;
    func_L01_0040E050(s+0x20);
    if(hadTimer && *(f32 *)(s+0x20)<=0.0f) {
        if(func_L01_005119E0(-1)) func_003A52A0(3,0,object);
    }
    if(*(s32 *)(s+0x2C) && func_0038CAD0((s32)(s+0x2C))) func_L01_004EAA80();
    if((*(s32 *)(D_001D52FC+0x1A4) & D_001A4BE0.fireButton) && !func_L01_005119E0(-1)) {
        func_003A52A0(1,0,object);
        D_L01_001E1790=17;
    }
    if(!D_L01_001D6694 && *(f32 *)(s+0x20)==0.0f && !D_001A4BE0.noFiring && object[0x42]<2 &&
       (*(s32 *)(D_001D52FC+0x1A0)&D_001A4BE0.fireButton) && D_001A4BE0.handTicks>=19 && allowed) {
        if(func_L01_005119E0(-1)) {
            func_003A52A0(0,0,object);
            func_L01_005118D0(-1,1);
            func_L01_0031D218(object,(u8 *)position,(u8 *)velocity);
            func_L01_00444F38(object,2,0,2,0);
            func_L01_0031D1D8(object,(s32)position,(s32)velocity);
            func_L01_004EA7D8(-1);
            *(s32 *)(s+0x2C)=13;
            *(s32 *)(s+0x28)=func_L01_003F2058(D_L01_002AE840,0);
        }
        if(!(*(s32 *)(D_001D52FC+0x1A0)&D_001A4BE0.fireButton) || !func_L01_005119E0(-1) || !D_001A4BE0.firing) {
            if(*(s32 *)(s+0x28)>=0) {
                func_L01_003F2278(*(s32 *)(s+0x28),0);
                *(s32 *)(s+0x28)=-1;
            }
        }
        *(f32 *)(s+0x20)=1.0f / ((Weapon_0031CCE8 *)D_L01_002C5600)[D_001425C0[0x13]].cooldown;
    }
    func_L01_00404A10(func_L01_0031D398,object);
}
