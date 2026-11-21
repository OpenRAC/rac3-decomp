/* functional: high. Applies a damage hit to a moving object (health bar object): reads the attacker/collision record, scales damage by the attacker multipliers, subtracts health, and classifies the hit result (0 none, 1-6: light/heavy/kill/special) then triggers the reaction callbacks; draft verified block by block against the PAL asm, callees mapped to catalogue names, compiles; only register allocation and scheduling differ from retail. */
typedef struct M_0048C560 M_0048C560;
typedef struct H_0048C560 {
 float health; short threshold; char pad06[0x11]; unsigned char kind;
} H_0048C560;
typedef struct E_0048C560 { H_0048C560 *health; char pad04[0x1c]; void *extra; } E_0048C560;
struct M_0048C560 {
 char p00[0x18]; float f18; char p1c[4]; unsigned char b20; char p21[0x13];
 unsigned short flags34; char p36[0x32]; E_0048C560 *state;
 char p6c[0x29]; unsigned char b95; char p96[0x12]; unsigned char bA8; char pA9; short id;
 char pAC[0x14]; float vec[4]; char pD0[0x30];
};
typedef struct A_0048C560 {
 char p00[7]; unsigned char b07; char p08[8]; unsigned char b10; char p11[9]; unsigned char b1A;
 char p1b[0x1d]; unsigned short f38; char p3a[6]; float f40; int tick; unsigned char b48;
 char p49[15]; float f58, f5c; char p60[0x10]; short owner; char p72[3]; unsigned char b75;
 char p76; unsigned char b77; char p78[0x30]; float fA8,fAC; int padB0; int flagsB4, fB8, fBC;
} A_0048C560;
typedef struct C_0048C560 {
 char p00[0x10]; unsigned int vector[4]; M_0048C560 *owner; char p24[4]; unsigned char kind;
 char p29[3]; float damage; int flags;
} C_0048C560;
typedef unsigned int Q_0048C560 __attribute__((mode(TI)));
extern M_0048C560 *D_001DCD4C_sda;
extern int D_L40_0024112C[];
extern int D_001D5A1C_sda;
int func_L40_0048C560(M_0048C560 *m, A_0048C560 *a, int special, int mode, int force)
{
 extern void func_L01_0044ABD0(M_0048C560 *, A_0048C560 *);
 extern void func_L01_00452E60(M_0048C560 *, A_0048C560 *);
 extern C_0048C560 *func_L01_00447490(M_0048C560 *, int, int);
 extern int func_0038CB00(void *);
 extern void func_0038CAD0(void *);
 extern float func_L01_004474E8(M_0048C560 *, C_0048C560 *);
 extern int func_L01_00452F30(M_0048C560 *, A_0048C560 *);
 extern void func_L01_00455E18(M_0048C560 *, void *, H_0048C560 *);
 extern void func_L01_00459BE8(M_0048C560 *, int, float);
 extern void func_0038CE20(void *, void *, float);
 extern int func_003C56E0(M_0048C560 *, A_0048C560 *, void *, int, int);
 extern void func_L01_004450F0(M_0048C560 *, int, int);
 extern void func_L01_00454370(M_0048C560 *, A_0048C560 *);
 extern void func_003C4A40(M_0048C560 *, A_0048C560 *);
 float v[4] __attribute__((aligned(16)));
 int result=0, isTen; float old, damage; int one;
 H_0048C560 *h; void *extra; C_0048C560 *c;
 if (!(m->flags34 & 0x20)) return 0;
 extra=m->state->extra; h=m->state->health;
 if (!a || !h) return 0;
 func_L01_0044ABD0(m,a);
 one=1;
 func_L01_00452E60(m,a);
 old=0.0f;
 {int mask=0x10000;if(mode)mask=one;c=func_L01_00447490(m,mask,0);}
 isTen=0;
 if (!func_0038CB00((char *)h+6)) c=0;
 func_0038CAD0(&a->fBC);
 if(c){
  isTen=one; old=c->damage; if(c->kind!=10)isTen=0;
  if(isTen && m->id==0x1b39 && h->health<=0.0f) isTen=0;
  if(a->fA8!=0.0f && c->owner && m->id==c->owner->id) c->damage=old*a->fA8;
  if(special) c->damage*=a->fAC;
 }
 damage=func_L01_004474E8(m,c);
 m->bA8=255;
 if(func_L01_00452F30(m,a) || m->f18<a->f40){damage=h->health;c=0;}
 if(!isTen) h->health-=damage;
 if(extra)func_L01_00455E18(m,extra,h);
 if(damage==0.0f)return 0;
 func_L01_00459BE8(m,h->kind,damage);
 a->owner=-1;
 if(c && c->owner)a->owner=c->owner-D_001DCD4C_sda;
 {
 float t=h->threshold*a->f58;
 int n=300;
 if(t<=0.0f)n=90;
 if(!a->b77){long d=D_L40_0024112C[0]-a->tick; if(d<=0)d=-d;
 if((n*5+2)/6<d && damage<t)damage=t;}
 if(isTen) result=3;
 else {
 if(h->health<=0.0f) result=4;
 else if(h->threshold*a->f5c<=damage)result=3;
 else if(h->threshold*a->f58<=damage)result=2;
 else if(damage!=0.0f && !a->b77 && c && c->owner && c->owner->id==0x47)result=2;
 else if(old!=0.0f)result=1;
 if(h->health<=0.0f && m->id==0x19db)result=5;
 if(c && c->owner && c->owner->id==0x1843 && !a->fB8){result=2;if(h->health<=0.0f)result=4;}
 if(special && (unsigned)(result-1)<=2)result=6;
 }
 }
 if(!result || (a->f38&3))return 0;
 if(m->b95==a->b48 && result<4){if(a->b75)return 0;if(a->b1A<2)return 0;}
 if(c && (c->flags&1))*(Q_0048C560 *)v=*(Q_0048C560 *)c->vector;
 else{func_0038CE20(v,m->vec,-1.0f);v[2]=1.0f;v[3]=5627.9248046875f;}
 {
 int allow=1;
 if((a->flagsB4&1) && (a->b10==255 || m->b20==a->b10) && (a->b48==255 || m->b95==a->b48)){if(result!=4)allow=0;}
 if((!a->fBC && !force) || h->health<=0.0f){
 if(allow){
 if(func_003C56E0(m,a,v,result,-1)){
 a->tick=D_001D5A1C_sda;
 if(a->b48!=255 && a->b48)func_L01_004450F0(m,a->b10,a->b48);
 else if(a->b10!=255 && a->b10)func_L01_004450F0(m,a->b10,-1);
 a->b1A=0;func_L01_00454370(m,a);
 }
 return result;
 }
 }
 a->b07=255;func_003C4A40(m,a);
 }
 return result;
}
