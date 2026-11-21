/* functional: medium. Camera/hero contact handler for a hero-contact moby (self = camera trigger moby, other = the touching object): decodes the hero state of other and the player's primary/secondary objects; while the contact lasts it counts frames in base[player].+0x20 (flag +0x28), steers the camera via func_003E9250 with the heading vector, and at 6 frames either latches a flag (state 32) or sets self+0x7C=5; when the contact target stops matching it resets the counters and, if the contact was live and the primary is state 0, updates the statistics block D_001A7C10 (count, best score, flags bit), checks the entry direction against the moby's +0xC0 axis (80 degree limit, else func_003F5AC0) and arms a 25-frame cooldown base[player].+0x30. A non-zero cooldown then calls func_003E9250 with a smaller angle. Branches, constants and offsets checked against PAL asm. NOTE: retail passes the heading vector in a1 to func_003E9250 (and that function passes it on to func_003E8FE8); the file's current (s32, f32, f32) prototype omits it, so it must become (s32, f32 *vec, f32 a, f32 b) before this compiles in context */
extern Entry_3E6C58 D_L01_001E2A40[];
extern M_3E6CA8 *D_L01_001DF804;
extern s32 D_L01_001DF700[2];
__asm__(".extern D_L01_001DF700, 8");
extern s32 D_001D4C38;
extern s32 D_001D545C;
typedef struct {
    u8 pad[0x40]; q128 position;
    u8 p50[8]; f32 yaw;
    u8 p5C[0xF0-0x5C]; u8 *moby;
    u8 pF4[8]; s32 target;
} Motion_003EAC70;
typedef struct {
    u8 p0[0x50]; u8 *primary, *secondary;
    u8 p58[0x90-0x58]; f32 direction[4];
    u8 pA0[0x150-0xA0]; Motion_003EAC70 motion;
    u8 p250[0x460-0x250];
} Entry_003EAC70;
typedef struct {
    u8 pad[0x198]; u16 count;
    u8 p19A[2]; u32 best, flags;
} Stats_003EAC70;
extern Stats_003EAC70 D_001A7C10;
typedef union { q128 q; f32 f[4]; } Vec_003EAC70;
s32 func_L01_003EAC70(u8 *self,u8 *other) {
    extern s32 func_L01_003F7350(q128 *,f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_003E9250(s32,f32 *,f32,f32);
    extern f32 func_0038CE68(f32 *,f32 *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern f32 func_0038CEA8(f32 *);
    extern f32 func_0038D0C8(f32);
    extern void func_L01_003F5AC0(s32,s32);
    extern s32 func_0038CB00(u8 *);
    struct { Vec_003EAC70 v,a,b; } t;
    Entry_003EAC70 *e=(Entry_003EAC70 *)&D_L01_001E2A40[*(s32 *)(self+0x94)];
    Motion_003EAC70 *m=&e->motion;
    u8 *base=(u8 *)D_L01_001DF804[*(s16 *)(self+0x84)].p1C;
    u8 *primary;
    u16 kind;
    u8 *query;
    f32 denom;
    f32 zero;
    if(D_L01_001DF700[*(s32 *)(self+0x94)]) {
        D_L01_001DF700[*(s32 *)(self+0x94)]=0;
        return 0;
    }
    D_L01_001DF700[*(s32 *)(self+0x94)]=0;
    if(m->target==*(s16 *)(self+0x86) || m->target==81) {
        primary=e->primary;
        kind=*(u16 *)(other+0x86);
        if((s16)kind==32 || (((s16)kind==0 || (s16)kind==10 || (s16)kind==14 || (s16)kind==2) &&
           ((s16)kind==32 || *(s16 *)(primary+0x86)==0 || *(s16 *)(primary+0x86)==10 || *(s16 *)(primary+0x86)==14 || *(s16 *)(primary+0x86)==2))) {
            t.v.q=m->position;
            query=(u8 *)func_L01_003F7350(&t.v.q,0.25f);
            if(query && (*(u32 *)(query+0x18)&1)) return 0;
            *(s16 *)(base+*(s32 *)(self+0x94)*2+0x28)=1;
            *(s16 *)(base+*(s32 *)(self+0x94)*2+0x30)=0;
            ++*(s16 *)(base+*(s32 *)(self+0x94)*2+0x20);
            if(*(s16 *)(base+*(s32 *)(self+0x94)*2+0x20)>=6) {
                if((e->secondary && *(s16 *)(e->secondary+0x86)==32) || *(s16 *)(primary+0x86)==32) {
                    base[0x3C+*(s32 *)(self+0x94)]=1;
                    return 1;
                }
                if(*(s16 *)(primary+0x86)==0) self[0x7C]=5;
                return 1;
            }
            if((e->secondary && *(s16 *)(e->secondary+0x86)==32) || *(s16 *)(primary+0x86)==32) {
                base[0x3C+*(s32 *)(self+0x94)]=1;
                return 1;
            }
            t.v.f[0]=func_0038D098(m->yaw);
            t.v.f[1]=func_0038D0B0(m->yaw);
            t.v.f[2]=0.0f;
            func_L01_003E9250(*(s32 *)(self+0x94),t.v.f,0.06981317f,t.v.f[2]);
        } else {
            *(s16 *)(base+*(s32 *)(self+0x94)*2+0x20)=0;
            *(s16 *)(base+*(s32 *)(self+0x94)*2+0x28)=0;
        }
    } else {
        *(s16 *)(base+*(s32 *)(self+0x94)*2+0x20)=0;
        if(*(s16 *)(base+*(s32 *)(self+0x94)*2+0x28)) {
            *(s16 *)(base+*(s32 *)(self+0x94)*2+0x28)=0;
            if(*(s16 *)(e->primary+0x86)==0) {
                Stats_003EAC70 *stats=&D_001A7C10;
                if(stats->count<65535) stats->count++;
                if(stats->best < (D_001D4C38*5+2)/6) stats->best=(D_001D4C38*5+2)/6;
                stats->flags |= (1 << D_001D545C) | 0x80000000;
                primary=(u8 *)e->direction;
                func_0038CE20(t.v.f,(f32 *)primary,func_0038CE68((f32 *)primary,(f32 *)e->primary));
                zero=0.0f;
                __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(t.a) : "m"(*(Vec_003EAC70 *)e->primary),"m"(t.v) : "vf1","vf2");
                func_0038CE20(t.v.f,(f32 *)primary,func_0038CE68((f32 *)primary,(f32 *)(m->moby+0xC0)));
                __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(t.b) : "m"(*(Vec_003EAC70 *)(m->moby+0xC0)),"m"(t.v) : "vf1","vf2");
                primary=(u8 *)&t.b;
                denom=func_0038CEA8((f32 *)primary);
                if(denom!=zero) {
                    denom *= func_0038CEA8(t.a.f);
                    if(denom!=zero && 1.5707964f-func_0038D0C8(func_0038CE68((f32 *)primary,t.a.f)/denom)>=1.3962634f) {
                        func_L01_003F5AC0(*(s32 *)(self+0x94),1);
                        return 0;
                    }
                }
                *(s16 *)(base+*(s32 *)(self+0x94)*2+0x30)=25;
            }
        }
    }
    if(*(s16 *)(base+*(s32 *)(self+0x94)*2+0x30)) {
        if(*(s16 *)(e->primary+0x86)==32) return 0;
        if(e->secondary && *(s16 *)(e->secondary+0x86)!=32) return 0;
        func_0038CB00(base+*(s32 *)(self+0x94)*2+0x30);
        t.v.f[0]=func_0038D098(m->yaw);
        t.v.f[1]=func_0038D0B0(m->yaw);
        t.v.f[2]=0.0f;
        func_L01_003E9250(*(s32 *)(self+0x94),t.v.f,0.13962634f,t.v.f[2]);
    }
    return 0;
}
