# !/usr/bin/perl
use warnings;
use strict;

my $n = 0;
my $num_ei = 0;

print "Digite o numero de frases: ";
$n=<>;
my @a = (1..$n);

open(my $f1, '>', 'texto.txt') or die $!;

for(@a){
    print "$_ - ";
    $a = <>;
    print $f1 "$a";
}

close $f1;
open(f2, '<', 'texto.txt') or die $!;

while(<f2>){
   print $_;
   if(/ei/){
        $num_ei=$num_ei+1;
    }
}
close(f2);

print "\n\nnumero de frases que tem 'ei' = $num_ei\n";
