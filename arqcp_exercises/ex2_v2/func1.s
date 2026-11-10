.section .text
    .global can_travel

can_travel:
    # int can_travel(unsigned long long *robot);
    # a0 = robot
    # ===========================================
    
    lhu t0, 0(a0) # ponto a
    lhu t1, 2(a0) # ponto b
    lhu t2, 4(a0) # Bateria
    lhu t3, 6(a0) # Estado --> (0 = operacional, qualquer outro valor = avaria)
    bnez t3, .not_ready # Check if the robot is ready to travel (estado != 0)

    sub t0, t1, t0 # ponto b - ponto a --> number of km for the trip
    bgez t0, .ready # Check if the distance is positive (ponto b >= ponto a)

.ready:
    li t4, 2 # Load immediate value 2 into t4
    mul t0, t0, t4 # (ponto b - ponto a) * 2 --> number of km for the trip * 2
    bgtu t0, t2, .not_ready # Check if the battery is sufficient for the trip (battery < distance * 2)
  
    li a0, 1 # Set return value to 1 (ready to travel)
    ret


.not_ready:
    li a0, 0 # Set return value to 0 (not ready to travel)
    ret
    