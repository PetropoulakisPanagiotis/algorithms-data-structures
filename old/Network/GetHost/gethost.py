import socket

def get_host_by_addr(addr):

    try:

        host_name = socket.gethostbyaddr(addr)

    except socket.herror:

        return "Unable to find host name. Maybe ip is wrong"

    return host_name


def get_host_by_name(name):

    try:

        addr = socket.gethostbyname(name)

    except socket.herror:

        return "Unable to find host address. Maybe host name is wrong"

    return addr

