
function fib(n)
  if n < 2 then return n end
  return fib(n - 2) + fib(n - 1)
end


function adder(x)

  return function (y) return x + y end
end

function bar(a, b, c)
  print(a, b, c)
  return 4, 8, 15, 16, 23, 42
end


-- Вызов функции с одной таблицей в качестве аргумента
-- не требует круглых скобок:
function h(x) print(x.key1) end
h{key1 = 'Sonmi~451'}  -- Печатает 'Sonmi~451'.

function metafraction.__add(f1, f2)
  local sum = {}
  sum.b = f1.b * f2.b
  sum.a = f1.a * f2.b + f2.a * f1.b
  return sum
end                  

function Dog:makeSound()             
  print('I say ' .. self.sound)
end

mrDog = Dog:new()                      
mrDog:makeSound()