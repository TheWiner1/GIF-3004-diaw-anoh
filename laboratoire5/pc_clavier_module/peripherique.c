#include <linux/init.h>             // Macros spécifiques des fonctions d'un module
#include <linux/module.h>           // En-tête général des modules noyau
#include <linux/device.h>           // Pour créer un pilote
#include <linux/kernel.h>           // Différentes définitions de types liés au noyau
#include <linux/gpio.h>             // Pour accéder aux GPIO du Raspberry Pi
#include <linux/fs.h>               // Pour accéder au système de fichier et créer un fichier spécial dans /dev
#include <linux/uaccess.h>          // Permet d'accéder à copy_to_user et copy_from_user
#include <linux/kthread.h>          // Utilisation des threads noyau
#include <linux/delay.h>            // Fonctions d'attente, en particulier msleep
#include <linux/string.h>           // Différentes fonctions de manipulation de string, plus memset et memcpy
#include <linux/mutex.h>            // Mutex et synchronisation
#include <linux/interrupt.h>        // Définit les symboles pour les interruptions et les tasklets
#include <linux/atomic.h>           // Synchronisation par valeur atomique

/* file_operations */
#define BUF_SIZE 30000
static char buffer[BUF_SIZE];
static size_t num = 0; /* Number of available bytes in the buffer */
#define DEV_NAME "Labo5_setr_Driver"
#define CLS_NAME "setr"


////Bibliographie fonction appel systéme fichier/////////
/////Référence et source librairie externe
///////Link : laboratoire 4 Gif 3004
//////Link : http://index-of.es/Programming/Programmation%20Noyau%20Sous%20Linux%20.%20Pilotes%20En%20Mode%20Caractere.pdf

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Diaw_Erwin");
MODULE_DESCRIPTION("Code Kernel for transfer data to userspace");

static ssize_t dev_write(struct file *file, const char *buf, size_t count, loff_t *ppos);
static ssize_t dev_read(struct file *file, char *buf, size_t count, loff_t *ppos);
static int dev_open(struct inode *inode, struct file *file);
static int dev_release(struct inode *inode, struct file *file);


static struct file_operations fops = {
  .read = dev_read,
  .write = dev_write,
  .open = dev_open,
  .release = dev_release,
};

static int major = 0; /* Major number */
static struct class*  setrClasse  = NULL;   // Contiendra les informations sur la classe de notre pilote
static struct device* setrDevice = NULL;    // Contiendra les informations sur le périphérique associé
static int    majorNumber;                  // Numéro donné par le noyau à notre pilote

static int __init Labo5_setr_Driver_init(void){
    printk(KERN_INFO "Labo5_setr_Driver : Initialisation du driver commencee\n");

    // On enregistre notre pilote
    majorNumber = register_chrdev(0, DEV_NAME, &fops);
    if (majorNumber<0){
      printk(KERN_ALERT "Labo5_setr_Driver : Erreur lors de l'appel a register_chrdev!\n");
      return majorNumber;
    }

    // Création de la classe de périphérique
    setrClasse = class_create(THIS_MODULE, CLS_NAME);
    if (IS_ERR(setrClasse)){
      unregister_chrdev(majorNumber, DEV_NAME);
      printk(KERN_ALERT "Labo5_setr_Driver : Erreur lors de la creation de la classe de peripherique\n");
      return PTR_ERR(setrClasse);
    }

    // Création du pilote de périphérique associé
    setrDevice = device_create(setrClasse, NULL, MKDEV(majorNumber, 0), NULL, DEV_NAME);
    if (IS_ERR(setrDevice)){
      class_destroy(setrClasse);
      unregister_chrdev(majorNumber, DEV_NAME);
      printk(KERN_ALERT "Labo5_setr_Driver : Erreur lors de la creation du pilote de peripherique\n");
      return PTR_ERR(setrDevice);
    }
    printk(KERN_INFO "Labo5_setr_Driver : Fin de l'Initialisation!\n"); // Made it! device was initialized

    return 0;
}


static ssize_t dev_write(struct file *file, const char *buf, size_t count, loff_t *ppos)
{
 size_t value;
 value = min((size_t)BUF_SIZE, count);
 if (value)
   if (copy_from_user(buffer, buf, value))
     return -EFAULT;
 num = value; /* Destructive write (overwrite previous data if any) */
 printk(KERN_DEBUG "Labo5_setr_Driver: wrote %d/%d chars %s\n", value, count, buffer);
 return value;
}


static ssize_t dev_read(struct file *file, char *buf, size_t count, loff_t *ppos)
{
 size_t value;
 value = min(num, count);
 if (value)
  if (copy_to_user(buf, buffer, value))
    return -EFAULT;
 num = 0; /* Destructive read (no more data after a read) */
 printk(KERN_DEBUG "Labo5_setr_Driver: read %d/%d chars %s\n", value, count, buffer);
 return value;
}


static int dev_open(struct inode *inode, struct file *file)
{
   printk(KERN_INFO "Labo5_setr_Driver: open()\n");
   return 0;
}
static int dev_release(struct inode *inode, struct file *file)
{
  printk(KERN_INFO "Labo5_setr_Driver: release()\n");
  return 0;
}



static void __exit Labo5_setr_Driver_exit(void){
  
    device_destroy(setrClasse, MKDEV(majorNumber, 0));
    class_unregister(setrClasse);
    class_destroy(setrClasse);
    unregister_chrdev(majorNumber, DEV_NAME);
    printk(KERN_INFO "Labo5_setr_Driver : Terminaison du driver\n");
}


module_init(Labo5_setr_Driver_init);
module_exit(Labo5_setr_Driver_exit);
