my @v = (3567,23,34,1111,2,5);
my $a = @v;
my @w = $a;
my %h = (3=>6, 6=>8);
my $b = %h;
my @t = %h;
my %j = $a;
my %g = @v;

print "v = @v\n";
print "h = ";
while ( ($k,$v) = each %h ) {
    print "$k => $v, ";
}
print "\na = $a\n";
print "w = @w\n";
print "b = $b\n";
print "t = @t\n";
print "j = ";
while ( ($k,$v) = each %j ) {
    print "$k => $v, ";
}
print "\ng = ";
while ( ($k,$v) = each %g ) {
    print "$k => $v, ";
}
