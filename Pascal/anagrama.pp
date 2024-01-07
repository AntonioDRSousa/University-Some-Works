program anagrama;

var 
	v:array[0..256] of integer;
	i,j:integer;
	s1,s2:string;
	b:boolean=true;

begin
	write('string 1 -> ');
	readln(s1);
	write('string 2 -> ');
	readln(s2);
	
	for i:=0 to 256 do
	begin
		v[i]:=0;
	end;
	
	for i:=0 to length(s1) do
	begin
		v[ord(s1[i])]:=v[ord(s1[i])]+1;
	end;
	
	for i:=0 to length(s2) do
	begin
		v[ord(s2[i])]:=v[ord(s2[i])]-1;
	end;
	
	for i:=0 to 256 do
	begin
		if v[i]<>0 then
		begin
			b:=false;
			break;
		end;
	end;
	
	if b then
	begin
		writeln('s1 anagrama de s2');
	end
	else
	begin
		writeln('s1 nao anagrama de s2');
	end;	
end.
