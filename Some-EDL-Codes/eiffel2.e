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

    a:INTEGER assign set_a
    set_a(y:INTEGER)
        do
            a:=y
        end
    

    make
        local
            a:INTEGER
        do
            print (a)
        end