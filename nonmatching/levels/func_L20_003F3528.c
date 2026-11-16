/* PAL reconstruction, 2026-11-16 (P05): 597 raw positional word
 * differences with -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as. Both repeated ribbon/branch rendering
 * passes are reconstructed from retail, using vu0.h helpers and ordinary
 * packet stores. The 0x2F0 frame agrees, but pointer spills, saved-register
 * allocation, loop invariants and VU0 load/output allocation differ.
 * Explicit next counters did not improve the raw score. Broad draft,
 * not a byte-exact implementation or a full-build match.
 */
#include "common.h"
#include "vu0.h"
typedef struct { vu0_v4 v[4]; s32 col[4]; f32 uv[4][2]; long r70,r78,r80,r88; } Packet_3F3528;
extern vu0_v4 D_L20_001E2E00;
extern f32 D_L20_001DF3B4[];
extern f32 D_L20_001DF3B0[4][2];
__asm__(".extern D_L20_001DF3B0, 4");
extern s32 D_001DF38C_sda,D_001DF390_sda,D_001DF394_sda,D_001DF398_sda,D_001DF39C_sda;
__asm__(".extern D_001DF38C_sda, 4");
__asm__(".extern D_001DF390_sda, 4");
__asm__(".extern D_001DF394_sda, 4");
__asm__(".extern D_001DF398_sda, 4");
__asm__(".extern D_001DF39C_sda, 4");
extern long func_00389598(s32);
extern void func_0038D328(void *,void *);
extern void func_0038D5B0(void *,void *);
extern void func_0038D000(void *,void *,void *);
extern void func_0038CE90(void *,void *,void *);
extern void func_0038CF68(void *,void *,f32);
extern void func_003D2DA0(void *,void *,s32);
void func_L20_003F3528(u8 *obj) {
    Packet_3F3528 p[3];
    vu0_v4 mat[4], inv[4], dir, prev, curr, a,b;
    u8 *s=*(u8 **)(obj+0x68);
    s32 i,j,k,next,nextK;
    long tex,mode;

    func_0038D328(mat,s+0x650);
    func_0038D5B0(inv,mat);
    *(vu0_q *)&mat[3]=*(vu0_q *)(obj+0x10);
    vec_sub_ba(&dir,&D_L20_001E2E00,obj+0x10);
    func_0038D000(&dir,&dir,inv);
    tex=func_00389598(D_001DF38C_sda);
    mode=(long)D_001DF390_sda | ((long)D_001DF394_sda<<2) | ((long)D_001DF398_sda<<4) | ((long)D_001DF39C_sda<<6) | 0x8000000000L;
    p[0].r78=p[1].r78=p[2].r78=tex;
    p[0].r80=p[1].r80=p[2].r80=0xFF9000000260L;
    p[0].r88=p[1].r88=p[2].r88=mode;
    p[0].r70=p[1].r70=p[2].r70=0;
    for(i=0;i<4;i++) {
        p[0].uv[i][1]=p[1].uv[i][1]=p[2].uv[i][1]=D_L20_001DF3B4[i*2];
        p[0].col[i]=p[1].col[i]=p[2].col[i]=*(s32 *)(s+0x44);
    }
    qzero(&curr);
    for(i=0;i<31;i++) {
        *(vu0_q *)&prev=*(vu0_q *)&curr;
        if(i<30) {
            vec_sub_ab(&b,s+0x50+i*16,s+0x70+i*16);
            vec_sub_ab(&a,s+0x60+i*16,&dir);
            func_0038CE90(&curr,&a,&b);
            func_0038CF68(&curr,&curr,0.1f);
        } else qzero(&curr);
        for(j=0;j<4;j++) {
            if(j<2) {
                *(vu0_q *)&p[0].v[j]=*(vu0_q *)(s+0x50+i*16);
                if(j&1) vec_add_ab(&p[0].v[j],&p[0].v[j],&prev);
                else vec_sub_ab(&p[0].v[j],&p[0].v[j],&prev);
            } else {
                *(vu0_q *)&p[0].v[j]=*(vu0_q *)(s+0x60+i*16);
                if(j&1) vec_add_ab(&p[0].v[j],&p[0].v[j],&curr);
                else vec_sub_ab(&p[0].v[j],&p[0].v[j],&curr);
            }
            p[0].uv[j][0]=D_L20_001DF3B0[j][0]+(i%4)*0.25f;
        }
        func_003D2DA0(&p[0],mat,0);
    }
    for(k=0;k<4;k=nextK) {
        nextK=k+1;
        if(s[0x48+k]<31 && s[0x48+k]>=0) {
            qzero(&curr);
            for(i=0;i<3;i=next) {
                *(vu0_q *)&prev=*(vu0_q *)&curr;
                if(i<2) {
                    vec_sub_ab(&b,s+0x450+i*64+k*16,s+0x4D0+i*64+k*16);
                    vec_sub_ab(&a,s+0x490+i*64+k*16,&dir);
                    func_0038CE90(&curr,&a,&b);
                    func_0038CF68(&curr,&curr,0.1f);
                } else qzero(&curr);
                if(i==0) *(vu0_q *)&prev=*(vu0_q *)&curr;
                next=i+1;
                for(j=0;j<4;j++) {
                    if(j<2) {
                        *(vu0_q *)&p[0].v[j]=*(vu0_q *)(s+0x450+i*64+k*16);
                        if(j&1) vec_add_ab(&p[0].v[j],&p[0].v[j],&prev);
                        else vec_sub_ab(&p[0].v[j],&p[0].v[j],&prev);
                    } else {
                        *(vu0_q *)&p[0].v[j]=*(vu0_q *)(s+0x490+i*64+k*16);
                        if(j&1) vec_add_ab(&p[0].v[j],&p[0].v[j],&curr);
                        else vec_sub_ab(&p[0].v[j],&p[0].v[j],&curr);
                    }
                    p[0].uv[j][0]=D_L20_001DF3B0[j][0]+(i%4)*0.25f;
                }
                func_003D2DA0(&p[0],mat,0);
            }
        }
    }

    func_0038D328(mat,s+0xc60);
    func_0038D5B0(inv,mat);
    *(vu0_q *)&mat[3]=*(vu0_q *)(obj+0x10);
    vec_sub_ba(&dir,&D_L20_001E2E00,obj+0x10);
    func_0038D000(&dir,&dir,inv);
    tex=func_00389598(D_001DF38C_sda);
    mode=(long)D_001DF390_sda | ((long)D_001DF394_sda<<2) | ((long)D_001DF398_sda<<4) | ((long)D_001DF39C_sda<<6) | 0x8000000000L;
    p[0].r78=p[1].r78=p[2].r78=tex;
    p[0].r80=p[1].r80=p[2].r80=0xFF9000000260L;
    p[0].r88=p[1].r88=p[2].r88=mode;
    p[0].r70=p[1].r70=p[2].r70=0;
    for(i=0;i<4;i++) {
        p[0].uv[i][1]=p[1].uv[i][1]=p[2].uv[i][1]=D_L20_001DF3B4[i*2];
        p[0].col[i]=p[1].col[i]=p[2].col[i]=*(s32 *)(s+0x44);
    }
    qzero(&curr);
    for(i=0;i<31;i++) {
        *(vu0_q *)&prev=*(vu0_q *)&curr;
        if(i<30) {
            vec_sub_ab(&b,s+0x660+i*16,s+0x680+i*16);
            vec_sub_ab(&a,s+0x670+i*16,&dir);
            func_0038CE90(&curr,&a,&b);
            func_0038CF68(&curr,&curr,0.1f);
        } else qzero(&curr);
        for(j=0;j<4;j++) {
            if(j<2) {
                *(vu0_q *)&p[0].v[j]=*(vu0_q *)(s+0x660+i*16);
                if(j&1) vec_add_ab(&p[0].v[j],&p[0].v[j],&prev);
                else vec_sub_ab(&p[0].v[j],&p[0].v[j],&prev);
            } else {
                *(vu0_q *)&p[0].v[j]=*(vu0_q *)(s+0x670+i*16);
                if(j&1) vec_add_ab(&p[0].v[j],&p[0].v[j],&curr);
                else vec_sub_ab(&p[0].v[j],&p[0].v[j],&curr);
            }
            p[0].uv[j][0]=D_L20_001DF3B0[j][0]+(i%4)*0.25f;
        }
        func_003D2DA0(&p[0],mat,0);
    }
    for(k=0;k<4;k=nextK) {
        nextK=k+1;
        if(s[0x48+k]<31 && s[0x48+k]>=0) {
            qzero(&curr);
            for(i=0;i<3;i=next) {
                *(vu0_q *)&prev=*(vu0_q *)&curr;
                if(i<2) {
                    vec_sub_ab(&b,s+0xa60+i*64+k*16,s+0x4D0+i*64+k*16);
                    vec_sub_ab(&a,s+0xaa0+i*64+k*16,&dir);
                    func_0038CE90(&curr,&a,&b);
                    func_0038CF68(&curr,&curr,0.1f);
                } else qzero(&curr);
                if(i==0) *(vu0_q *)&prev=*(vu0_q *)&curr;
                next=i+1;
                for(j=0;j<4;j++) {
                    if(j<2) {
                        *(vu0_q *)&p[0].v[j]=*(vu0_q *)(s+0xa60+i*64+k*16);
                        if(j&1) vec_add_ab(&p[0].v[j],&p[0].v[j],&prev);
                        else vec_sub_ab(&p[0].v[j],&p[0].v[j],&prev);
                    } else {
                        *(vu0_q *)&p[0].v[j]=*(vu0_q *)(s+0xaa0+i*64+k*16);
                        if(j&1) vec_add_ab(&p[0].v[j],&p[0].v[j],&curr);
                        else vec_sub_ab(&p[0].v[j],&p[0].v[j],&curr);
                    }
                    p[0].uv[j][0]=D_L20_001DF3B0[j][0]+(i%4)*0.25f;
                }
                func_003D2DA0(&p[0],mat,0);
            }
        }
    }
}
