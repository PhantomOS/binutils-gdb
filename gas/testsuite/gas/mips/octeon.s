	.text
	.set noreorder

foo:
        baddu   $17,$18,$19
        baddu   $2,$3

        bbit0   $19,22,foo
        nop
        bbit032 $30,11,foo
        nop
        bbit0   $8,42,foo
        nop

        bbit1   $3,31,foo
        nop
        bbit132 $24,10,foo
        nop
        bbit1   $14,46,foo
        nop

        cins    $25,$10,22,2
        cins    $9,17,29
        cins32  $15,$2,18,8
        cins32  $22,9,22
        cins    $24,$31,32,31
        cins    $15,37,5

        dmul    $19,$24,$28
        dmul    $21,$25

        pop     $8,$19
        pop     $2
        dpop    $15,$22
        dpop    $12

        exts    $4,$28,27,15
        exts    $15,17,6
        exts32  $4,$13,10,8
        exts32  $15,11,20
        exts    $7,$4,54,9
        exts    $25,37,25

        mtm0    $26
        mtm1    $19
        mtm2    $18

        mtp0    $16
        mtp1    $25
        mtp2    $9

        seq     $29,$23,$24
        seq     $6,$28

        seqi    $17,$15,-512
        seqi    $16,38

        seq     $5,$4,-274      # seqi
        seq     $12,511         # seqi
        seq     $30,$25,512     # xori $30,$25,512;sltiu $30,$30,1
        seq     $2,$12,-777     # daddiu $2,$12,777;sltiu $2,$2,1
        seq     $10,$30,0x10000 # lui $1,0x1; seq $10,$30,$1
        seq     $30,$25,-47366  # lui $1,0xffff; ori $1,$1,0x46fa; seq $30,$25,$1

        sne     $6,$2,$2
        sne     $23,$20

        snei    $4,$16,-313
        snei    $26,511

        sne     $21,$23,-512    # snei
        sne     $12,81          # snei

        sne     $4,$14,889      # xori $4,$14,889;sltu $4,$0,$4
        sne     $24,$13,-513    # daddiu $24,$13,513;sltu $24,$0,$24
        sne     $10,$30,119250  # lui $1,0x1; ori $1,$1,0xd1d2; sne $10,$30,$1
        sne     $30,$25,-0x8000 # li $1,-32768; sne $30,$25,$1

	synciobdma
        syncs
        syncw
        syncws

        v3mulu  $21,$10,$21
        v3mulu  $20,$10
        vmm0    $3,$19,$16
        vmm0    $31,$9
        vmulu   $29,$10,$17
        vmulu   $27,$6
