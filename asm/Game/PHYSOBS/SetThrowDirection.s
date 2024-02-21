.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

.section .rodata
.align 3
dlabel jtbl_80011CD0
/* 24D0 80011CD0 C4900680 */ .word .L800690C4
/* 24D4 80011CD4 FC900680 */ .word .L800690FC
/* 24D8 80011CD8 24920680 */ .word .L80069224
/* 24DC 80011CDC 34930680 */ .word .L80069334
/* 24E0 80011CE0 4C930680 */ .word .L8006934C
/* 24E4 80011CE4 00000000 */ .word 0x00000000
.size jtbl_80011CD0, . - jtbl_80011CD0


.section .text
/* Generated by spimdisasm 1.21.0 */

glabel SetThrowDirection
/* 59878 80069078 E0FFBD27 */  addiu      $sp, $sp, -0x20
/* 5987C 8006907C 1800B2AF */  sw         $s2, 0x18($sp)
/* 59880 80069080 2190C000 */  addu       $s2, $a2, $zero
/* 59884 80069084 1C00BFAF */  sw         $ra, 0x1C($sp)
/* 59888 80069088 1400B1AF */  sw         $s1, 0x14($sp)
/* 5988C 8006908C 1000B0AF */  sw         $s0, 0x10($sp)
/* 59890 80069090 00004386 */  lh         $v1, 0x0($s2)
/* 59894 80069094 00000000 */  nop
/* 59898 80069098 0500622C */  sltiu      $v0, $v1, 0x5
/* 5989C 8006909C B7004010 */  beqz       $v0, .L8006937C
/* 598A0 800690A0 21888000 */   addu      $s1, $a0, $zero
/* 598A4 800690A4 0180023C */  lui        $v0, %hi(jtbl_80011CD0)
/* 598A8 800690A8 D01C4224 */  addiu      $v0, $v0, %lo(jtbl_80011CD0)
/* 598AC 800690AC 80180300 */  sll        $v1, $v1, 2
/* 598B0 800690B0 21186200 */  addu       $v1, $v1, $v0
/* 598B4 800690B4 0000628C */  lw         $v0, 0x0($v1)
/* 598B8 800690B8 00000000 */  nop
/* 598BC 800690BC 08004000 */  jr         $v0
/* 598C0 800690C0 00000000 */   nop
.L800690C4:
/* 598C4 800690C4 4801A28C */  lw         $v0, 0x148($a1)
/* 598C8 800690C8 00000000 */  nop
/* 598CC 800690CC 04004010 */  beqz       $v0, .L800690E0
/* 598D0 800690D0 00000000 */   nop
/* 598D4 800690D4 78004584 */  lh         $a1, 0x78($v0)
/* 598D8 800690D8 39A40108 */  j          .L800690E4
/* 598DC 800690DC 00000000 */   nop
.L800690E0:
/* 598E0 800690E0 7800A584 */  lh         $a1, 0x78($a1)
.L800690E4:
/* 598E4 800690E4 14004696 */  lhu        $a2, 0x14($s2)
/* 598E8 800690E8 B6DE010C */  jal        PhysicsSetVelFromZRot
/* 598EC 800690EC 21202002 */   addu      $a0, $s1, $zero
/* 598F0 800690F0 1A004286 */  lh         $v0, 0x1A($s2)
/* 598F4 800690F4 DFA40108 */  j          .L8006937C
/* 598F8 800690F8 7C0122AE */   sw        $v0, 0x17C($s1)
.L800690FC:
/* 598FC 800690FC 0400508E */  lw         $s0, 0x4($s2)
/* 59900 80069100 5C002426 */  addiu      $a0, $s1, 0x5C
/* 59904 80069104 5C000526 */  addiu      $a1, $s0, 0x5C
/* 59908 80069108 87E8000C */  jal        MATH3D_AngleFromPosToPos
/* 5990C 8006910C 0800F0AC */   sw        $s0, 0x8($a3)
/* 59910 80069110 21202002 */  addu       $a0, $s1, $zero
/* 59914 80069114 00140200 */  sll        $v0, $v0, 16
/* 59918 80069118 14004696 */  lhu        $a2, 0x14($s2)
/* 5991C 8006911C B6DE010C */  jal        PhysicsSetVelFromZRot
/* 59920 80069120 032C0200 */   sra       $a1, $v0, 16
/* 59924 80069124 21200002 */  addu       $a0, $s0, $zero
/* 59928 80069128 0C000524 */  addiu      $a1, $zero, 0xC
/* 5992C 8006912C 92D1000C */  jal        INSTANCE_Query
/* 59930 80069130 7C0120AE */   sw        $zero, 0x17C($s1)
/* 59934 80069134 21404000 */  addu       $t0, $v0, $zero
/* 59938 80069138 7401278E */  lw         $a3, 0x174($s1)
/* 5993C 8006913C 7801268E */  lw         $a2, 0x178($s1)
/* 59940 80069140 0200E104 */  bgez       $a3, .L8006914C
/* 59944 80069144 2118E000 */   addu      $v1, $a3, $zero
/* 59948 80069148 23180300 */  negu       $v1, $v1
.L8006914C:
/* 5994C 8006914C 0200C104 */  bgez       $a2, .L80069158
/* 59950 80069150 2110C000 */   addu      $v0, $a2, $zero
/* 59954 80069154 23100200 */  negu       $v0, $v0
.L80069158:
/* 59958 80069158 2A104300 */  slt        $v0, $v0, $v1
/* 5995C 8006915C 15004010 */  beqz       $v0, .L800691B4
/* 59960 80069160 00000000 */   nop
/* 59964 80069164 5C002386 */  lh         $v1, 0x5C($s1)
/* 59968 80069168 1400028D */  lw         $v0, 0x14($t0)
/* 5996C 8006916C 8300E010 */  beqz       $a3, .L8006937C
/* 59970 80069170 23284300 */   subu      $a1, $v0, $v1
/* 59974 80069174 8100A010 */  beqz       $a1, .L8006937C
/* 59978 80069178 00000000 */   nop
/* 5997C 8006917C 8801228E */  lw         $v0, 0x188($s1)
/* 59980 80069180 00000000 */  nop
/* 59984 80069184 18004500 */  mult       $v0, $a1
/* 59988 80069188 12180000 */  mflo       $v1
/* 5998C 8006918C 00000000 */  nop
/* 59990 80069190 00000000 */  nop
/* 59994 80069194 1A006700 */  div        $zero, $v1, $a3
/* 59998 80069198 12180000 */  mflo       $v1
/* 5999C 8006919C 60002486 */  lh         $a0, 0x60($s1)
/* 599A0 800691A0 1C00028D */  lw         $v0, 0x1C($t0)
/* 599A4 800691A4 00000000 */  nop
/* 599A8 800691A8 23104400 */  subu       $v0, $v0, $a0
/* 599AC 800691AC 80A40108 */  j          .L80069200
/* 599B0 800691B0 18004700 */   mult      $v0, $a3
.L800691B4:
/* 599B4 800691B4 5E002386 */  lh         $v1, 0x5E($s1)
/* 599B8 800691B8 1800028D */  lw         $v0, 0x18($t0)
/* 599BC 800691BC 6F00C010 */  beqz       $a2, .L8006937C
/* 599C0 800691C0 23284300 */   subu      $a1, $v0, $v1
/* 599C4 800691C4 6D00A010 */  beqz       $a1, .L8006937C
/* 599C8 800691C8 00000000 */   nop
/* 599CC 800691CC 8801228E */  lw         $v0, 0x188($s1)
/* 599D0 800691D0 00000000 */  nop
/* 599D4 800691D4 18004500 */  mult       $v0, $a1
/* 599D8 800691D8 12180000 */  mflo       $v1
/* 599DC 800691DC 00000000 */  nop
/* 599E0 800691E0 00000000 */  nop
/* 599E4 800691E4 1A006600 */  div        $zero, $v1, $a2
/* 599E8 800691E8 12180000 */  mflo       $v1
/* 599EC 800691EC 60002486 */  lh         $a0, 0x60($s1)
/* 599F0 800691F0 1C00028D */  lw         $v0, 0x1C($t0)
/* 599F4 800691F4 00000000 */  nop
/* 599F8 800691F8 23104400 */  subu       $v0, $v0, $a0
/* 599FC 800691FC 18004600 */  mult       $v0, $a2
.L80069200:
/* 59A00 80069200 12400000 */  mflo       $t0
/* 59A04 80069204 00000000 */  nop
/* 59A08 80069208 00000000 */  nop
/* 59A0C 8006920C 1A000501 */  div        $zero, $t0, $a1
/* 59A10 80069210 12100000 */  mflo       $v0
/* 59A14 80069214 43180300 */  sra        $v1, $v1, 1
/* 59A18 80069218 23104300 */  subu       $v0, $v0, $v1
/* 59A1C 8006921C DFA40108 */  j          .L8006937C
/* 59A20 80069220 7C0122AE */   sw        $v0, 0x17C($s1)
.L80069224:
/* 59A24 80069224 5C002426 */  addiu      $a0, $s1, 0x5C
/* 59A28 80069228 04005026 */  addiu      $s0, $s2, 0x4
/* 59A2C 8006922C 87E8000C */  jal        MATH3D_AngleFromPosToPos
/* 59A30 80069230 21280002 */   addu      $a1, $s0, $zero
/* 59A34 80069234 21202002 */  addu       $a0, $s1, $zero
/* 59A38 80069238 00140200 */  sll        $v0, $v0, 16
/* 59A3C 8006923C 14004696 */  lhu        $a2, 0x14($s2)
/* 59A40 80069240 B6DE010C */  jal        PhysicsSetVelFromZRot
/* 59A44 80069244 032C0200 */   sra       $a1, $v0, 16
/* 59A48 80069248 7401278E */  lw         $a3, 0x174($s1)
/* 59A4C 8006924C 7801268E */  lw         $a2, 0x178($s1)
/* 59A50 80069250 0200E104 */  bgez       $a3, .L8006925C
/* 59A54 80069254 2118E000 */   addu      $v1, $a3, $zero
/* 59A58 80069258 23180300 */  negu       $v1, $v1
.L8006925C:
/* 59A5C 8006925C 0200C104 */  bgez       $a2, .L80069268
/* 59A60 80069260 2110C000 */   addu      $v0, $a2, $zero
/* 59A64 80069264 23100200 */  negu       $v0, $v0
.L80069268:
/* 59A68 80069268 2A104300 */  slt        $v0, $v0, $v1
/* 59A6C 8006926C 15004010 */  beqz       $v0, .L800692C4
/* 59A70 80069270 7C0120AE */   sw        $zero, 0x17C($s1)
/* 59A74 80069274 04004386 */  lh         $v1, 0x4($s2)
/* 59A78 80069278 5C002286 */  lh         $v0, 0x5C($s1)
/* 59A7C 8006927C 3F00E010 */  beqz       $a3, .L8006937C
/* 59A80 80069280 23286200 */   subu      $a1, $v1, $v0
/* 59A84 80069284 3D00A010 */  beqz       $a1, .L8006937C
/* 59A88 80069288 00000000 */   nop
/* 59A8C 8006928C 8801228E */  lw         $v0, 0x188($s1)
/* 59A90 80069290 00000000 */  nop
/* 59A94 80069294 18004500 */  mult       $v0, $a1
/* 59A98 80069298 12180000 */  mflo       $v1
/* 59A9C 8006929C 00000000 */  nop
/* 59AA0 800692A0 00000000 */  nop
/* 59AA4 800692A4 1A006700 */  div        $zero, $v1, $a3
/* 59AA8 800692A8 12200000 */  mflo       $a0
/* 59AAC 800692AC 04000286 */  lh         $v0, 0x4($s0)
/* 59AB0 800692B0 60002386 */  lh         $v1, 0x60($s1)
/* 59AB4 800692B4 00000000 */  nop
/* 59AB8 800692B8 23104300 */  subu       $v0, $v0, $v1
/* 59ABC 800692BC C4A40108 */  j          .L80069310
/* 59AC0 800692C0 18004700 */   mult      $v0, $a3
.L800692C4:
/* 59AC4 800692C4 02000386 */  lh         $v1, 0x2($s0)
/* 59AC8 800692C8 5E002286 */  lh         $v0, 0x5E($s1)
/* 59ACC 800692CC 2B00C010 */  beqz       $a2, .L8006937C
/* 59AD0 800692D0 23286200 */   subu      $a1, $v1, $v0
/* 59AD4 800692D4 2900A010 */  beqz       $a1, .L8006937C
/* 59AD8 800692D8 00000000 */   nop
/* 59ADC 800692DC 8801228E */  lw         $v0, 0x188($s1)
/* 59AE0 800692E0 00000000 */  nop
/* 59AE4 800692E4 18004500 */  mult       $v0, $a1
/* 59AE8 800692E8 12180000 */  mflo       $v1
/* 59AEC 800692EC 00000000 */  nop
/* 59AF0 800692F0 00000000 */  nop
/* 59AF4 800692F4 1A006600 */  div        $zero, $v1, $a2
/* 59AF8 800692F8 12200000 */  mflo       $a0
/* 59AFC 800692FC 04000286 */  lh         $v0, 0x4($s0)
/* 59B00 80069300 60002386 */  lh         $v1, 0x60($s1)
/* 59B04 80069304 00000000 */  nop
/* 59B08 80069308 23104300 */  subu       $v0, $v0, $v1
/* 59B0C 8006930C 18004600 */  mult       $v0, $a2
.L80069310:
/* 59B10 80069310 12180000 */  mflo       $v1
/* 59B14 80069314 00000000 */  nop
/* 59B18 80069318 00000000 */  nop
/* 59B1C 8006931C 1A006500 */  div        $zero, $v1, $a1
/* 59B20 80069320 12100000 */  mflo       $v0
/* 59B24 80069324 43200400 */  sra        $a0, $a0, 1
/* 59B28 80069328 23104400 */  subu       $v0, $v0, $a0
/* 59B2C 8006932C DFA40108 */  j          .L8006937C
/* 59B30 80069330 7C0122AE */   sw        $v0, 0x17C($s1)
.L80069334:
/* 59B34 80069334 21202002 */  addu       $a0, $s1, $zero
/* 59B38 80069338 14004696 */  lhu        $a2, 0x14($s2)
/* 59B3C 8006933C D2DE010C */  jal        PhysicsSetVelFromRot
/* 59B40 80069340 04004526 */   addiu     $a1, $s2, 0x4
/* 59B44 80069344 DFA40108 */  j          .L8006937C
/* 59B48 80069348 00000000 */   nop
.L8006934C:
/* 59B4C 8006934C 04004286 */  lh         $v0, 0x4($s2)
/* 59B50 80069350 00000000 */  nop
/* 59B54 80069354 740122AE */  sw         $v0, 0x174($s1)
/* 59B58 80069358 06004286 */  lh         $v0, 0x6($s2)
/* 59B5C 8006935C 00000000 */  nop
/* 59B60 80069360 780122AE */  sw         $v0, 0x178($s1)
/* 59B64 80069364 08004286 */  lh         $v0, 0x8($s2)
/* 59B68 80069368 00000000 */  nop
/* 59B6C 8006936C 7C0122AE */  sw         $v0, 0x17C($s1)
/* 59B70 80069370 16004286 */  lh         $v0, 0x16($s2)
/* 59B74 80069374 00000000 */  nop
/* 59B78 80069378 880122AE */  sw         $v0, 0x188($s1)
.L8006937C:
/* 59B7C 8006937C 1C00BF8F */  lw         $ra, 0x1C($sp)
/* 59B80 80069380 1800B28F */  lw         $s2, 0x18($sp)
/* 59B84 80069384 1400B18F */  lw         $s1, 0x14($sp)
/* 59B88 80069388 1000B08F */  lw         $s0, 0x10($sp)
/* 59B8C 8006938C 0800E003 */  jr         $ra
/* 59B90 80069390 2000BD27 */   addiu     $sp, $sp, 0x20
.size SetThrowDirection, . - SetThrowDirection
