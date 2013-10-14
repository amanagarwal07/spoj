import random, sys

def miller_rabin_pass(a, s, d, n):
    a_to_power = pow(a, d, n)
    if a_to_power == 1:
        return True
    for i in xrange(s-1):
        if a_to_power == n - 1:
            return True
        a_to_power = (a_to_power * a_to_power) % n
    return a_to_power == n - 1


def miller_rabin(n):
    d = n - 1
    s = 0
    while d % 2 == 0:
        d >>= 1
        s += 1
	
    for repeat in xrange(20):
        a = 0
        while a == 0:
            a = random.randrange(n)
        if not miller_rabin_pass(a, s, d, n):
            return False
    return True
if __name__ == "__main__":
	    	   mod=2147483648
		   t=1
		   cnt=0
		   while t>0:
			cnt=cnt+1
			if t==1:
				print 0
        		elif miller_rabin(t)==True:
		 	    print 1
			else:
			     print 0
			t=(t+1234567890)%mod
		        if cnt>=33333333:
			  exit(0)
