/* functional: medium. fixed draft: hit-record copy offsets were 0x10 too high (normal at hero+0x250, capsule at +0x260 per retail); 47 words differ, all scheduling/regalloc */
extern u8 D_001A4BE0_004F0640[];
typedef struct {
    vu0_q before;
    vu0_q center;
    vu0_q normal;
} HitVectors_004F0640;
typedef struct {
    u8 p0[0x80]; vu0_q center;
    u8 p90[0x250-0x90]; vu0_q normal, capsule;
    u8 p280[0x28C-0x270]; s32 poly;
    u8 p290[0x2A7-0x290]; u8 wall;
} HeroCopy_004F0640;
extern vu0_q D_L01_001EAA30[];
s32 func_L01_004F0640(s32 mode) {
    extern void func_L01_00512490(void);
    extern f32 func_0038CE68(void *,void *);
    extern void func_0038D000(void *,void *,void *);
    extern void func_L01_00511280(void *,void *,f32);
    extern void func_L01_005110E8(void *,s32,f32,f32,f32);
    extern s32 func_L01_003FB640(void *,s32,f32,void *);
    extern s32 func_L01_003FC480(void *,s32,f32,f32,void *);
    extern s32 func_L01_003FDCA0(void *,s32,f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *,void *,f32);
    struct { vu0_v4 old,offset,delta; } v;
    u8 *h=D_001A4BE0_004F0640;
    vu0_v4 *delta;
    s32 flat;
    s32 i;
    s32 hit;
    vu0_q *position;
    u8 *record;
    f32 depth;
    if (*(s16 *)(h+0x1F0)) return 1;
    *(vu0_q *)&v.old=*(vu0_q *)(h+0x80);
    qzero(&v.offset);
    if (*(s16 *)(h+0x2886)) {
        func_L01_00512490();
        *(s16 *)(h+0x2886)=0;
    }
    if (func_0038CE68(h+0x20,h+0x2E0) > -0.92f) flat=1; else flat=0;
    if (*(s32 *)(h+0x25CC)==15) goto type15;
    if (*(s32 *)(h+0x25CC)!=17) goto other_type;
    goto offset_done;
type15:
        qzero(&v.offset);
        v.offset.z=0.8f;
        func_0038D000(&v.offset,&v.offset,*(u8 **)(h+0x25C0)+0xC0);
    goto offset_done;
other_type:
        if (h[0x25F4] || *(s16 *)(h+0x218) || flat) {
            u8 *p=D_001A4BE0_004F0640;
            if (p[0x25E4]==2) func_L01_00511280(&v.offset,&v.offset,5.0f);
            else if (p[0x25F4]==1 || *(s16 *)(p+0x218)) func_L01_005110E8(&v.offset,0,0.0f,0.0f,0.6f);
            else if (D_L01_001D673C) func_L01_00511280(&v.offset,&v.offset,0.77f);
            else func_L01_005110E8(&v.offset,0,0.0f,0.0f,*(f32 *)(p+0x274));
        } else v.offset.z=*(f32 *)(h+0x274);
offset_done:
    vec_add_ba(D_001A4C60,D_001A4C60,&v.offset);
    {
    u8 *p;
    vu0_v4 *cur;
    i=0;
    goto test;
loop_body:
    if (*(s32 *)(p+0x25CC)==15) {
        if (!func_L01_003FB640(p+0x80,36,0.54f,*(void **)(p+0x25C0))) goto done;
        goto copy_hit;
    }
    cur=(vu0_v4 *)(p+0x80);
    if (p[0x25F4] || flat) {
        hit=func_L01_003FB640(cur,36,*(f32 *)(p+0x284),*(void **)(p+0x25C0));
    } else {
        depth=*(f32 *)(p+0x270)-*(f32 *)(p+0x274);
        if (depth<0.05f) depth=0.05f;
        hit=func_L01_003FC480(cur,36,*(f32 *)(p+0x284),depth,*(void **)(p+0x25C0));
    }
    if (*(s16 *)(p+0x1E6)==0) hit |= func_L01_003FDCA0(cur,0,*(f32 *)(p+0x284));
    if (!hit) goto done;
copy_hit:
    {
        HeroCopy_004F0640 *t;
        HitVectors_004F0640 *r;
        position=D_001A4C60;
        record=(u8 *)D_L01_001EAA30;
        t=(HeroCopy_004F0640 *)((u8 *)position-0x80);
        r=(HitVectors_004F0640 *)(record-0x10);
        t->poly=*(s32 *)(record-0x18);
        t->center=r->center;
        t->normal=r->normal;
        t->capsule=r->before;
        t->wall=1;
        i++;
    }
test:
    if (i>=8) goto done;
    p=D_001A4BE0_004F0640;
    if (*(s32 *)(p+0x25CC)!=17) goto loop_body;
    if (func_L01_003FB640(p+0x80,36,0.6f,*(void **)(p+0x25C0))) goto copy_hit;
done:;
    }
    vec_sub_ba(D_001A4C60,D_001A4C60,&v.offset);
    vec_sub_ba(&v.delta,D_001A4C60,&v.old);
    delta=&v.delta;
    if (func_0038CEA8(delta) > *(f32 *)((u8 *)D_001A4C60+0x204)*3.0f) {
        if(mode==15) {
        if(v.delta.x > 512.0f) v.delta.x=512.0f;
        else if(v.delta.x < -512.0f) v.delta.x=-512.0f;
        if(v.delta.y > 512.0f) v.delta.y=512.0f;
        else if(v.delta.y < -512.0f) v.delta.y=-512.0f;
        if(v.delta.z > 512.0f) v.delta.z=512.0f;
        else if(v.delta.z < -512.0f) v.delta.z=-512.0f;
        {
        u8 *tail=D_001A4BE0_004F0640;
        func_0038CF68(delta,delta,*(f32 *)(tail+0x284));
        vec_add_ab(tail+0x80,&v.old,&v.delta);
        }
        }
        return -1;
    }
    return 1;
}
