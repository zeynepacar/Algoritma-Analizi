Problem: NxN’lik bir oyun tahtasında N adet renk her satırda farklı sıra ile yer almaktadır. Bir satırdaki renklerin sıralanışı, renkler sağa doğru dairesel kaydırılarak değiştirilebilmektedir. Örneğin satırdaki renkler sırası ile kırmızı, mavi, yeşil, mor ise satır 1 defa sağa kaydırıldığında yeni sıralama mor, kırmızı, mavi, yeşil olur. Bir defa daha sağa kaydırılırsa yeşil, mor, kırmızı, mavi elde edilir. Son durumda her sütunda her renkten sadece 1 tane olacak şekilde oyun tahtasını geri-izleme(backtracking) yöntemi ile rekürsif olarak düzenleyen algoritmayı tasarlayınız.
İşlemler: Algoritmanızı tasarlarken aşağıdaki işlemleri yapınız.
1. Oyun tahtası 3 <= N <= 8 için NxN boyutunda olabilir.
2. Oyun tahtasının ilk durumunu giriş bilgisi olarak dışarıdan alınız.
3. Renkleri programda kullanırken kolaylık olması açısından matriste verilen her rengi bir sayıya denk
düşürerek kullanınız. Örneğin kullanıcıdan aldığınız soldaki renk matrisini sağdaki gibi bir sayı matrisine
dönüştürerek kullanmanız kolaylık sağlayacaktır.
Kırmızı Mavi Yeşil      5   2   4
Yeşil Mavi Kırmızı      4   2   5
Kırmızı Yeşil Mavi      5   4   2
4. Her satır için o satırdaki renkleri üst satırlara göre aynı sütunda aynı renk olmayacak şekilde sağa doğru kaydırınız. Eğer işlem yapılan satırda bu şart sağlanamıyorsa geri-izleme ile bir üst satıra dönerek yeni bir sıralama deneyiniz.

