class Queue:
    def __init__(self, *values):
        self.elemets = []
        for i in values:
            self.elemets.append(i)
 
    def __rshift__(self, n):
        if len(self.elemets) > n:
            new = Queue()
            new.elemets += self.elemets[n:]
            return new
        return Queue()
 
    def __add__(self, other):
        new = self.copy()
        new.elemets += other.elemets
        return new
 
    def __iadd__(self, other):
        self.elemets += other.elemets
        return self
 
    def __eq__(self, other):
        if self.elemets == other.elemets:
            return True
        return False
 
    def __str__(self):
        if self.elemets:
            self.elemets = list(map(str, self.elemets))
            elemets = ' -> '.join(self.elemets)
            return f'[{elemets}]'
        return '[]'
        
    def __next__(queue):
        new = queue.copy()
        new.elemets = new.elemets[1:]
        return new

    def append(self, *values):
        for i in values:
            self.elemets.append(i)
 
    def copy(self):
        new = Queue()
        new.elemets += self.elemets
        return new
 
    def pop(self):
        if self.elemets:
            first = self.elemets[0]
            del self.elemets[0]
            return first
 
    def extend(self, queue):
        self.elemets += queue.elemets
 
    def next(self):
        new = self.copy()
        new.elemets = new.elemets[1:]
        return new
 
q1 = Queue(1, 2, 3)
print(q1)
q1.append(4, 5)
print(q1)
qx = q1.copy()
print(qx.pop())
print(qx)
q2 = q1.copy()
print(q2)
print(q1 == q2, id(q1) == id(q2))  
q3 = q2.next()
print(q1, q2, q3, sep='\n')  
print(q1 + q3)  
q3.extend(Queue(1, 2))
print(q3)  
q4 = Queue(1, 2)
q4 += q3 >> 4
print(q4)  
q5 = next(q4)
print(q4)  
print(q5)