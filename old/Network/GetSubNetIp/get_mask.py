def get_sub_net_ip(ip, mask):
    sub_net_ip = ""
    count_1 = 0
    count_2 = 0

    # Convert given ip, "8.8.8.8" -> 8888#
    # Every loop manipulates each byte(8888) of ip and mask without "." and perform #
    # bitwise and to find sub net ip #
    for x in range(0,3):

        tmp1 = ip.find(".",count_1) # tmp1,tmp2: holds position of "."
        tmp2 = mask.find(".",count_2)

        sub_net_ip += str(int(ip[count_1:tmp1]) & int(mask[count_2:tmp2])) + "."

        if(x == 2):

            sub_net_ip += str(int(ip[tmp1 + 1:]) & int(mask[tmp2 + 1:]))

            break

        count_1 = tmp1 + 1 # Go to next character("8." ->"8.8")
        count_2 = tmp2 + 1

    return sub_net_ip
