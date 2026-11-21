/* functional: high. Camera placement for a hero-attached view: forward = hero look vector (hero table entry +0xF0 -> +0xE0, unit), camera position = hero position (+0x40) + forward scaled by 3.75 / 0.75 / 1.6 depending on hero byte +0x12B (2 / 1 / other); then rebuilds right/up from the player's up pointer (entry +0x54) and copies the basis to +0x40. Calls, constants and order checked against retail; only scheduling differs */
typedef int Q_003EA9C8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003EA9C8;
typedef struct { u8 pad[0x54]; f32 *up; u8 rest[0x460-0x58]; } Entry_003EA9C8;
extern u8 D_L01_001E2B90[];
extern Entry_3E6C58 D_L01_001E2A40[];
static __inline__ void add_003EA9C8(V_003EA9C8 *d,V_003EA9C8 *a,V_003EA9C8 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
      : "=m"(*d) : "m"(*a), "m"(*b) : "vf1","vf2");
}
void func_L01_003EA9C8(Obj_003E8C50 *obj) {
    extern void func_0038CF68(f32 *,f32 *,f32);
    extern void func_0038CE90(f32 *,f32 *,f32 *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    Q_003EA9C8 forward, offset;
    u8 *hero = D_L01_001E2B90 + obj->f94 * 0x460;
    func_0038CF68((f32 *)&forward,(f32 *)(*(u8 **)(hero+0xF0)+0xE0),1.0f);
    if(hero[0x12B]==2) {
        func_0038CE20((f32 *)&offset,(f32 *)&forward,3.75f);
    } else if(hero[0x12B]==1) {
        func_0038CE20((f32 *)&offset,(f32 *)&forward,0.75f);
    } else {
        func_0038CE20((f32 *)&offset,(f32 *)&forward,1.6f);
    }
    add_003EA9C8((V_003EA9C8 *)&obj->q30,(V_003EA9C8 *)(hero+0x40),(V_003EA9C8 *)&offset);
    *(Q_003EA9C8 *)((u8 *)obj+0x20)=forward;
    func_0038CE90((f32 *)((u8 *)obj+0x10),((Entry_003EA9C8 *)D_L01_001E2A40)[obj->f94].up,(f32 *)&forward);
    func_0038CF68((f32 *)((u8 *)obj+0x10),(f32 *)((u8 *)obj+0x10),1.0f);
    func_0038CE90((f32 *)obj,(f32 *)&forward,(f32 *)((u8 *)obj+0x10));
    *(Q_003EA9C8 *)((u8 *)obj+0x40)=*(Q_003EA9C8 *)obj;
}
