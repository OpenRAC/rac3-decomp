/* functional: high. PAL near-miss draft re-verified block by block against the asm (offsets, gp-relative D_001D6764/0x1D6770, count/max exits, fade of tex anim index); vu0 helpers replaced by plain sub helper (xyz minus, w from minuend); added a separate 3-quad temp for func_0038D308 (retail overlays it on pos). Frame is 0x30 bigger than retail; 237 diff words are scheduling/VU only */
typedef int Q_0044ED88 __attribute__((mode(TI)));
/* d.xyz = a.xyz - b.xyz; d.w = a.w (retail: lqc2/vsub.xyz/sqc2 with the minuend's w) */
static void sub_xyz_0044ED88(f32 *d, f32 *a, f32 *b) {
    f32 x = a[0] - b[0];
    f32 y = a[1] - b[1];
    f32 z = a[2] - b[2];
    f32 w = a[3];
    d[0] = x; d[1] = y; d[2] = z; d[3] = w;
}
extern u8 *D_L01_001E001C[];
extern s32 D_L01_001E0058[];
extern s16 *D_L01_0021DE20[];
__asm__(".extern D_L01_0021DE20, 16");
extern s32 D_L01_001D6768[];
extern s16 **D_001D6764_sda;
extern s32 D_001D6770_sda;
extern s16 **D_L01_001D676C[];
extern u8 *D_L01_001E0EDC[];
extern u8 *D_L01_001E0DD0;
__asm__(".extern D_L01_001E0DD0, 16");
void func_L01_0044ED88(u8 *obj, u8 *out, s32 max, s32 mobyid, s32 tieid, s32 shrubid, s32 tex, u8 *parent)
{
    extern void func_003C2EC0(u8 *, int, Q_0044ED88 *);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5B0(void *, void *);
    extern void func_0038D590(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern s32 func_00382498(s32, s32);
    extern int func_L01_0044EC78(int, u8 *, int, s128_44B9F8 *, s128_44B9F8 *, s128_44B9F8 *, void *);
    Q_0044ED88 joints[40][4];
    Q_0044ED88 inverse[3];
    Q_0044ED88 pos[1],a[1],b[1];
    Q_0044ED88 tmp[3];
    Q_0044ED88 mat[4];
    s32 njoints;
    s32 count;
    s32 i;
    if (max<=0) { out[0x4A]=0; return; }
    if (mobyid==-1 && tieid==mobyid && shrubid==tieid) { out[0x4A]=0; return; }
    njoints=0;
    if (parent!=0) {
        u8 *data=*(u8 **)(parent+0x24);
        s32 *n=*(s32 **)(data+0x1C);
        if(n!=0) njoints=*n;
        if(njoints!=0 && njoints<=40) { } else return;
        for(i=0;i<njoints;i++) func_003C2EC0(parent,i,joints[i]);
        *(u16 *)(parent+0x34)|=1;
        parent[0x31]=0;
    }
    count=0;
    func_0038D308(tmp,obj+0xF0);
    func_0038D5B0(mat,tmp);
    func_0038D590(inverse,mat);
    pos[0]=*(Q_0044ED88 *)(obj+0x10);
    {
    s16 *list0; u8 *p0,*base0; u8 *m0,*rotation0;
    if(mobyid!=-1 && mobyid<D_L01_001E0058[0] && (list0=*(s16 **)((s32)D_L01_0021DE20+(mobyid<<2)))!=0) {
        p0=out+0x30; base0=out;
        do {
            s32 id=*(u16 *)list0&0x7FFF;
            m0=D_L01_001E001C[0]+(id<<8);
            if(count>=max) goto finish;
            *(s16 *)(p0+0x18)=id;
            p0[0x1A]=2;
            p0[0x1C]=0;
            *(s32 *)(p0+0x10)=0;
            if(parent!=0) {
                *(u8 **)(p0+0x14)=parent;
                if(p0[0x1B]==255) {
                a[0]=*(Q_0044ED88 *)(m0+0x10);
                b[0]=*(Q_0044ED88 *)(m0+0xC0);
                p0[0x1B]=func_L01_0044EC78((int)parent,(u8 *)joints,njoints,a,b,pos,inverse);
                }
            }
            sub_xyz_0044ED88((f32 *)p0,(f32 *)(m0+0x10),(f32 *)pos);
            func_0038D000(p0,p0,inverse);
            rotation0=m0+0xC0;
            if(*(s32 *)(m0+0x24)==0) func_0038D308(rotation0,m0+0xF0);
            func_0038D5F0(base0,inverse,rotation0);
            p0+=0x50; base0+=0x50;
            *(u16 *)(m0+0x34)|=0x104;
            count++;
        } while(*list0++>=0);
    }
    }
    {
    s16 *list1; u8 *p1,*base1; u8 *m1,*rotation1;
    if(tieid!=-1) {
        s32 anim;
        if(tex>0) anim=func_00382498(0,tex);
        else anim=0;
        if(tieid<D_L01_001D6768[0] && (list1=D_001D6764_sda[tieid])!=0) {
            base1=out+count*0x50; p1=base1+0x30;
            do {
                s32 id=*(u16 *)list1&0x7FFF;
                m1=D_L01_001E0EDC[0]+(id<<6);
                if(count>=max) goto finish;
                base1[0x4C]=1;
                *(s16 *)(base1+0x48)=id;
                base1[0x4A]=2;
                *(s32 *)(base1+0x40)=0;
                if(parent!=0) {
                    *(u8 **)(base1+0x44)=parent;
                    if(base1[0x4B]==255) {
                    a[0]=*(Q_0044ED88 *)(m1+0x30);
                    b[0]=*(Q_0044ED88 *)m1;
                    base1[0x4B]=func_L01_0044EC78((int)parent,(u8 *)joints,njoints,a,b,pos,inverse);
                    }
                }
                if(tex>0) {
                    base1[0x4E]=tex+1;
                    base1[0x4F]=anim;
                    anim=(anim+1)%base1[0x4E];
                } else if(tex<0) base1[0x4E]=255;
                else base1[0x4E]=0;
                sub_xyz_0044ED88((f32 *)p1,(f32 *)(m1+0x30),(f32 *)pos);
                func_0038D000(p1,p1,inverse);
                p1+=0x50; count++;
                func_0038D5F0(base1,inverse,m1);
                base1+=0x50;
            } while(*list1++>=0);
        }
    }
    }
    {
    s16 *list2; u8 *p2,*base2; u8 *m2,*rotation2;
    if(shrubid!=-1 && shrubid<D_001D6770_sda && (list2=D_L01_001D676C[0][shrubid])!=0) {
        base2=out+count*0x50; p2=base2+0x30;
        do {
            s32 id=*(u16 *)list2&0x7FFF;
            m2=D_L01_001E0DD0+(id<<6);
            if(count>=max) goto finish;
            *(s16 *)(p2+0x18)=id;
            p2[0x1C]=2;
            p2[0x1A]=2;
            *(s32 *)(p2+0x10)=0;
            count++;
            sub_xyz_0044ED88((f32 *)p2,(f32 *)(m2+0x30),(f32 *)pos);
            func_0038D000(p2,p2,inverse);
            p2+=0x50;
            func_0038D5F0(base2,inverse,m2);
            base2+=0x50;
        } while(*list2++>=0);
    }
    }
finish:
    if(count!=0) (out+count*0x50)[-6]=1;
    else out[0x4A]=0;
}
