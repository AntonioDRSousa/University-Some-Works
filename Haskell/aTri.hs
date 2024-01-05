areaTriangulo::Double->Double->Double->Double
areaTriangulo a b c = c*h/2
    where
        cosA = ((b**2)+(c**2)-(a**2)) / (2*b*c)
        sinA = sqrt (1 - (cosA**2) )
        h = b*sinA
