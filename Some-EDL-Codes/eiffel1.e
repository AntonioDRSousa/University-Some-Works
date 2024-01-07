note
    description : "root class of the application"
    date        : "$Date$"
    revision    : "$Revision$"
    
class
    APPLICATION

inherit
    ARGUMENTS_32

create
    make
    
feature {NONE}
    

    make
        do
            print(soma(5,4))
        end
    
    soma(x:INTEGER;y:INTEGER):INTEGER
        local
            x:INTEGER
            y:INTEGER
        do
            x:=1
            y:=2
            Result:=x+y
        end

end