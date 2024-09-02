prog=motcache

# Normal usage

@test "Resultat final : MANDOLINE" {
    run ./$prog ./testeTxt/mandoline.txt
    [ "$status" -eq 0 ]
    [ "${lines[0]}" = "MANDOLINE" ]
}

@test "Verification matrice : MANDOLINE" {
    skip
    run ./$prog ./testeTxt/mandoline.txt
    [ "$status" -eq 0 ]
    [ "${lines[1]}" = "Matrice : " ]
    [ "${lines[2]}" = "AMETTENIRALC" ]
    [ "${lines[3]}" = "CGUITAREXIOV" ]
    [ "${lines[4]}" = "CASOOEMATMAT" ]
    [ "${lines[5]}" = "OMARJDCBHNBE" ]
    [ "${lines[6]}" = "RUXGNRLUAEAN" ]
    [ "${lines[7]}" = "DIOUAAATRLTO" ]
    [ "${lines[8]}" = "ENPEBBVFPATH" ]
    [ "${lines[9]}" = "OOHOEMILEBEP" ]
    [ "${lines[10]}" = "NMONROEUDMRO" ]
    [ "${lines[11]}" = "LRNAYBRTOYIL" ]
    [ "${lines[12]}" = "OAEILLIENCEY" ]
    [ "${lines[13]}" = "SHEPOLOCCIPX" ]
}

@test "Verification des mots :  MANDOLINE" {
    skip
    run ./$prog ./testeTxt/mandoline.txt
    [ "$status" -eq 0 ]
    [ "${lines[14]}" = "mots : " ]
    [ "${lines[15]}" = "ACCORDEON" ]
    [ "${lines[16]}" = "BANJO" ]
    [ "${lines[17]}" = "BATTERIE" ]
    [ "${lines[18]}" = "BOMBARDE" ]
    [ "${lines[19]}" = "CLARINETTE" ]
    [ "${lines[20]}" = "CLAVIER" ]
    [ "${lines[21]}" = "CYMBALE" ]
    [ "${lines[22]}" = "FLUTE" ]
    [ "${lines[23]}" = "GUITARE" ]
    [ "${lines[24]}" = "HARMONIUM" ]
    [ "${lines[25]}" = "HARPE" ]
    [ "${lines[26]}" = "LYRE" ]
    [ "${lines[27]}" = "ORGUE" ]
    [ "${lines[28]}" = "PIANO" ]
    [ "${lines[29]}" = "PICCOLO" ]
    [ "${lines[30]}" = "SAXOPHONE" ]
    [ "${lines[31]}" = "SOL" ]
    [ "${lines[32]}" = "TAMTAM" ]
    [ "${lines[33]}" = "TUBA" ]
    [ "${lines[34]}" = "VOIX" ]
    [ "${lines[35]}" = "XYLOPHONE" ]
}

@test "Resultat final : CALISSE" {
    run ./$prog ./testeTxt/calisse.txt
    [ "$status" -eq 0 ]
    [ "${lines[0]}" = "CALISSE" ]
}

@test "Verification matrice : CALISSE" {
    skip
    run ./$prog ./testeTxt/calisse.txt
    [ "$status" -eq 0 ]
    [ "${lines[1]}" = "Matrice : " ]
    [ "${lines[2]}" = "TRAVERSIERCE" ]
    [ "${lines[3]}" = "AEVACHEENIES" ]
    [ "${lines[4]}" = "LSILCEBEUQET" ]
    [ "${lines[5]}" = "SOUVERAINUMU" ]
    [ "${lines[6]}" = "TUSESSAHCEOA" ]
    [ "${lines[7]}" = "NTRADUIRELRI" ]
    [ "${lines[8]}" = "ETNETIURTSHR" ]
    [ "${lines[9]}" = "DICTIONEEICE" ]
    [ "${lines[10]}" = "IVROGNEEZOOE" ]
    [ "${lines[11]}" = "CRUELIBRENNN" ]
    [ "${lines[12]}" = "CTNEREFERSOU" ]
    [ "${lines[13]}" = "ARMEDRATUOML" ]
}

@test "Verification des mots :  CALISSE" {
    skip
    run ./$prog ./testeTxt/calisse.txt
    [ "$status" -eq 0 ]
    [ "${lines[14]}" = "mots : " ]
    [ "${lines[15]}" = "QUEBEC" ]
    [ "${lines[16]}" = "LIBRE" ]
    [ "${lines[17]}" = "SOUVERAIN" ]
    [ "${lines[18]}" = "TENTE" ]
    [ "${lines[19]}" = "RESOUT" ]
    [ "${lines[20]}" = "TRAVERSIER" ]
    [ "${lines[21]}" = "MONOCHROME" ]
    [ "${lines[22]}" = "ESTUAIRE" ]
    [ "${lines[23]}" = "QUESTIONS" ]
    [ "${lines[24]}" = "MOUTARDE" ]
    [ "${lines[25]}" = "VALVE" ]
    [ "${lines[26]}" = "TRADUIRE" ]
    [ "${lines[27]}" = "ACCIDENT" ]
    [ "${lines[28]}" = "EVACHEE" ]
    [ "${lines[29]}" = "SEINE" ]
    [ "${lines[30]}" = "IONS" ]
    [ "${lines[31]}" = "LUNE" ]
    [ "${lines[32]}" = "QUEL" ]
    [ "${lines[33]}" = "DICTION" ]
    [ "${lines[34]}" = "CHASSE" ]
    [ "${lines[35]}" = "TRUITE" ]
    [ "${lines[36]}" = "ARME" ]
    [ "${lines[37]}" = "REFERENT" ]
    [ "${lines[38]}" = "CRUEL" ]
    [ "${lines[39]}" = "IVROGNE" ]
    [ "${lines[40]}" = "REER" ]
    [ "${lines[41]}" = "REZ" ]
    [ "${lines[42]}" = "MUNI" ]
}

@test "Resultat final : PARESSEUX" {
    run ./$prog ./testeTxt/paresseux.txt
    [ "$status" -eq 0 ]
    [ "${lines[0]}" = "PARESSEUX" ]
}

@test "Verification matrice : PARESSEUX" {
    skip
    run ./$prog ./testeTxt/paresseux.txt
    [ "$status" -eq 0 ]
    [ "${lines[1]}" = "Matrice : " ]
    [ "${lines[2]}" = "ASTRONAUTEPE" ]
    [ "${lines[3]}" = "AOBOURREAUXP" ]
    [ "${lines[4]}" = "CLRMVAESLCEE" ]
    [ "${lines[5]}" = "HSBARMEEEHNR" ]
    [ "${lines[6]}" = "AAINIINSNAOV" ]
    [ "${lines[7]}" = "RNNEEFRCTRPI" ]
    [ "${lines[8]}" = "OEESRIURUIHE" ]
    [ "${lines[9]}" = "GDRQEEOIESIR" ]
    [ "${lines[10]}" = "NAIUSRTMUTLU" ]
    [ "${lines[11]}" = "ECEEEUSESIEE" ]
    [ "${lines[12]}" = "PELLERINEETE" ]
    [ "${lines[13]}" = "XETUASRISIOL" ]
}

@test "Verification des mots :  PARESSEUX" {
    skip
    run ./$prog ./testeTxt/paresseux.txt
    [ "$status" -eq 0 ]
    [ "${lines[14]}" = "mots : " ]
    [ "${lines[15]}" = "ASTRONAUTE" ]
    [ "${lines[16]}" = "EPERVIER" ]
    [ "${lines[17]}" = "ROMANESQUE" ]
    [ "${lines[18]}" = "TALENTUEUSES" ]
    [ "${lines[19]}" = "BOURREAUX" ]
    [ "${lines[20]}" = "OUVRIERE" ]
    [ "${lines[21]}" = "ARMEE" ]
    [ "${lines[22]}" = "LOISIRS" ]
    [ "${lines[23]}" = "PELLERIN" ]
    [ "${lines[24]}" = "SAUTE" ]
    [ "${lines[25]}" = "CADENAS" ]
    [ "${lines[26]}" = "CHAROGNE" ]
    [ "${lines[27]}" = "SOL" ]
    [ "${lines[28]}" = "EUCHARISTIE" ]
    [ "${lines[29]}" = "XENOPHILE" ]
    [ "${lines[30]}" = "RAMIFIER" ]
    [ "${lines[31]}" = "BINERIE" ]
    [ "${lines[32]}" = "ESCRIME" ]
    [ "${lines[33]}" = "RISTOURNE" ]
    [ "${lines[34]}" = "RUEE" ]
    [ "${lines[35]}" = "LETO" ]
}

@test "Resultat final : VENISE" {
    run ./$prog ./testeTxt/venise.txt
    [ "$status" -eq 0 ]
    [ "${lines[0]}" = "VENISE" ]
}

@test "Verification matrice : VENISE" {
    skip
    run ./$prog ./testeTxt/venise.txt
    [ "$status" -eq 0 ]
    [ "${lines[1]}" = "Matrice : " ]
    [ "${lines[2]}" = "NBLASPEZIAVA" ]
    [ "${lines[3]}" = "AEENRUOVILIR" ]
    [ "${lines[4]}" = "LRECNEROLFRB" ]
    [ "${lines[5]}" = "IGNERIVOLIAG" ]
    [ "${lines[6]}" = "MAAIEUODAPBE" ]
    [ "${lines[7]}" = "NMPNCEEALEGN" ]
    [ "${lines[8]}" = "IELIONMASTIE" ]
    [ "${lines[9]}" = "AEEMMNREMORS" ]
    [ "${lines[10]}" = "BSSIEEEALOMI" ]
    [ "${lines[11]}" = "LISREILNIRUT" ]
    [ "${lines[12]}" = "APOHRSAINRET" ]
    [ "${lines[13]}" = "ASSISEPPARME" ]
}

@test "Verification des mots :  VENISE" {
    skip
    run ./$prog ./testeTxt/venise.txt
    [ "$status" -eq 0 ]
    [ "${lines[14]}" = "mots : " ]
    [ "${lines[15]}" = "ALBA" ]
    [ "${lines[16]}" = "ASSISE" ]
    [ "${lines[17]}" = "ASTI" ]
    [ "${lines[18]}" = "BARI" ]
    [ "${lines[19]}" = "BERGAME" ]
    [ "${lines[20]}" = "BRA" ]
    [ "${lines[21]}" = "COME" ]
    [ "${lines[22]}" = "FLORENCE" ]
    [ "${lines[23]}" = "GELA" ]
    [ "${lines[24]}" = "GENES" ]
    [ "${lines[25]}" = "IMOLA" ]
    [ "${lines[26]}" = "LASPEZIA" ]
    [ "${lines[27]}" = "LIVOURNE" ]
    [ "${lines[28]}" = "MILAN" ]
    [ "${lines[29]}" = "NAPLES" ]
    [ "${lines[30]}" = "PADOUE" ]
    [ "${lines[31]}" = "PALERME" ]
    [ "${lines[32]}" = "PARME" ]
    [ "${lines[33]}" = "PISE" ]
    [ "${lines[34]}" = "RHO" ]
    [ "${lines[35]}" = "RIMINI" ]
    [ "${lines[36]}" = "RIVOLI" ]
    [ "${lines[37]}" = "ROME" ]
    [ "${lines[38]}" = "SIENNE" ]
    [ "${lines[39]}" = "TERNI" ]
    [ "${lines[40]}" = "TURIN" ]
}

@test "Resultat final : INTELLIGENT" {
    run ./$prog ./testeTxt/intelligent.txt
    [ "$status" -eq 0 ]
    [ "${lines[0]}" = "INTELLIGENT" ]
}

@test "Verification matrice : INTELLIGENT" {
    skip
    run ./$prog ./testeTxt/intelligent.txt
    [ "$status" -eq 0 ]
    [ "${lines[1]}" = "Matrice : " ]
    [ "${lines[2]}" = "PARCOURSILIT" ]
    [ "${lines[3]}" = "LONGTEMPSNLA" ]
    [ "${lines[4]}" = "AGNAMTPLANTE" ]
    [ "${lines[5]}" = "NEMERCREDILA" ]
    [ "${lines[6]}" = "TEMPERATUREP" ]
    [ "${lines[7]}" = "ELEPHANTEIRP" ]
    [ "${lines[8]}" = "NOISIVERLLUO" ]
    [ "${lines[9]}" = "ILONGTEMPSTR" ]
    [ "${lines[10]}" = "GPLOMBIERELT" ]
    [ "${lines[11]}" = "JOINTURENTUE" ]
    [ "${lines[12]}" = "ABANDONNERCR" ]
    [ "${lines[13]}" = "ACCIDENTELLE" ]
}

@test "Verification des mots :  INTELLIGENT" {
    skip
    run ./$prog ./testeTxt/intelligent.txt
    [ "$status" -eq 0 ]
    [ "${lines[14]}" = "mots : " ]
    [ "${lines[15]}" = "PLANTE" ]
    [ "${lines[16]}" = "MERCREDI" ]
    [ "${lines[17]}" = "PARCOURS" ]
    [ "${lines[18]}" = "MANGA" ]
    [ "${lines[19]}" = "LIT" ]
    [ "${lines[20]}" = "LA" ]
    [ "${lines[21]}" = "TEMPERATURE" ]
    [ "${lines[22]}" = "ELEPHANT" ]
    [ "${lines[23]}" = "CULTURE" ]
    [ "${lines[24]}" = "NOISIVER" ]
    [ "${lines[25]}" = "RIE" ]
    [ "${lines[26]}" = "APPORTER" ]
    [ "${lines[27]}" = "LONGTEMPS" ]
    [ "${lines[28]}" = "PLOMBIER" ]
    [ "${lines[29]}" = "ABANDONNER" ]
    [ "${lines[30]}" = "ACCIDENTELLE" ]
    [ "${lines[31]}" = "JOINTURE" ]
}

@test "Erreur : Demander entrer tous les fichier txt" {
    run ./$prog ./testeTxt/*.txt
    [ "$status" -eq 1 ]
    [ "${lines[0]}" = "trop d'argument" ]
}

@test "Erreur : Demande aucun fichier" {
    run ./$prog 
    [ "$status" -eq 1 ]
    [ "${lines[0]}" = "fichier manquant" ]
}