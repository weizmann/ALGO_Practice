import random
scale = 100
iter_scale = 10000
exchange_winner_count = 0;
for i in xrange(1,iter_scale):
    arr = range(1,scale + 1)
    random.shuffle(arr)
    get_first = arr[0]
    count = 0
    for num in arr[1:]:
        if num == 1:
            continue
        else:
            arr.remove(num)
            count = count + 1
        if count == scale - 2:
            break
    if arr[1] == 1:
        exchange_winner_count = exchange_winner_count + 1
    print i , " : " , get_first, arr[1]
print exchange_winner_count

