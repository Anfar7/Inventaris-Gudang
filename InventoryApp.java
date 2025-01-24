import java.awt.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Vector;
import javax.swing.*;

class Item {
    String kodeItem;
    String tanggalMasuk;

    Item(String kodeItem, String tanggalMasuk) {
        this.kodeItem = kodeItem;
        this.tanggalMasuk = tanggalMasuk;
    }

    @Override
    public String toString() {
        return "Kode Item: " + kodeItem + ", Tanggal Masuk: " + tanggalMasuk;
    }
}

class Pembeli {
    String ktp;
    String waktuDatang;
    String kodeItem;

    Pembeli(String ktp, String waktuDatang, String kodeItem) {
        this.ktp = ktp;
        this.waktuDatang = waktuDatang;
        this.kodeItem = kodeItem;
    }
}

public class InventoryApp {
    private JFrame frame;
    private Vector<Item> inventory = new Vector<>();
    private Queue<Pembeli> antrian = new LinkedList<>();
    private Vector<String> riwayatPenjualan = new Vector<>();

    public InventoryApp() {
        frame = new JFrame("Aplikasi Gudang");
        frame.setSize(600, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(6, 1));

        JButton btnEntriItem = new JButton("Entri Item Barang");
        JButton btnCetakBarang = new JButton("Cetak Daftar Barang");
        JButton btnCatatPembeli = new JButton("Catat Pembeli");
        JButton btnJualItem = new JButton("Jual Item Barang");
        JButton btnRiwayat = new JButton("Riwayat Penjualan");
        JButton btnKeluar = new JButton("Keluar");

        btnEntriItem.addActionListener(e -> entriItem());
        btnCetakBarang.addActionListener(e -> cetakBarang());
        btnCatatPembeli.addActionListener(e -> catatPembeli());
        btnJualItem.addActionListener(e -> jualItem());
        btnRiwayat.addActionListener(e -> riwayatPenjualan());
        btnKeluar.addActionListener(e -> System.exit(0));

        frame.add(btnEntriItem);
        frame.add(btnCetakBarang);
        frame.add(btnCatatPembeli);
        frame.add(btnJualItem);
        frame.add(btnRiwayat);
        frame.add(btnKeluar);

        frame.setVisible(true);
    }

    private void entriItem() {
        JFrame itemFrame = new JFrame("Entri Item");
        itemFrame.setSize(300, 200);
        itemFrame.setLayout(new GridLayout(3, 2));

        JTextField txtKodeItem = new JTextField();
        JTextField txtTanggalMasuk = new JTextField();
        JButton btnSubmit = new JButton("Submit");

        itemFrame.add(new JLabel("Kode Item:"));
        itemFrame.add(txtKodeItem);
        itemFrame.add(new JLabel("Tanggal Masuk:"));
        itemFrame.add(txtTanggalMasuk);
        itemFrame.add(btnSubmit);

        btnSubmit.addActionListener(e -> {
            String kode = txtKodeItem.getText();
            String tanggal = txtTanggalMasuk.getText();

            if (!kode.isEmpty() && !tanggal.isEmpty()) {
                inventory.add(new Item(kode, tanggal));
                JOptionPane.showMessageDialog(itemFrame, "Item berhasil ditambahkan!");
                itemFrame.dispose();
            } else {
                JOptionPane.showMessageDialog(itemFrame, "Mohon isi semua field!");
            }
        });

        itemFrame.setVisible(true);
    }

    private void cetakBarang() {
        JFrame listFrame = new JFrame("Daftar Barang");
        listFrame.setSize(400, 300);

        JTextArea textArea = new JTextArea();
        textArea.setEditable(false);

        for (Item item : inventory) {
            textArea.append(item.toString() + "\n");
        }

        JScrollPane scrollPane = new JScrollPane(textArea);
        listFrame.add(scrollPane);
        listFrame.setVisible(true);
    }

    private void catatPembeli() {
        JFrame pembeliFrame = new JFrame("Catat Pembeli");
        pembeliFrame.setSize(300, 250);
        pembeliFrame.setLayout(new GridLayout(4, 2));

        JTextField txtKTP = new JTextField();
        JTextField txtWaktuDatang = new JTextField();
        JTextField txtKodeItem = new JTextField();
        JButton btnSubmit = new JButton("Submit");

        pembeliFrame.add(new JLabel("KTP Pembeli:"));
        pembeliFrame.add(txtKTP);
        pembeliFrame.add(new JLabel("Waktu Datang:"));
        pembeliFrame.add(txtWaktuDatang);
        pembeliFrame.add(new JLabel("Kode Item:"));
        pembeliFrame.add(txtKodeItem);
        pembeliFrame.add(btnSubmit);

        btnSubmit.addActionListener(e -> {
            String ktp = txtKTP.getText();
            String waktu = txtWaktuDatang.getText();
            String kode = txtKodeItem.getText();

            if (!ktp.isEmpty() && !waktu.isEmpty() && !kode.isEmpty()) {
                antrian.add(new Pembeli(ktp, waktu, kode));
                JOptionPane.showMessageDialog(pembeliFrame, "Pembeli berhasil dicatat!");
                pembeliFrame.dispose();
            } else {
                JOptionPane.showMessageDialog(pembeliFrame, "Mohon isi semua field!");
            }
        });

        pembeliFrame.setVisible(true);
    }

    private void jualItem() {
        if (antrian.isEmpty() || inventory.isEmpty()) {
            JOptionPane.showMessageDialog(frame, "Tidak ada antrian atau barang!");
            return;
        }

        Pembeli pembeli = antrian.poll();
        Item item = inventory.remove(0);

        String transaksi = "Pembeli KTP: " + pembeli.ktp + " membeli item " + item.kodeItem
                + " (Tanggal Masuk: " + item.tanggalMasuk + ")";
        riwayatPenjualan.add(transaksi);

        JOptionPane.showMessageDialog(frame, transaksi);
    }

    private void riwayatPenjualan() {
        JFrame riwayatFrame = new JFrame("Riwayat Penjualan");
        riwayatFrame.setSize(400, 300);

        JTextArea textArea = new JTextArea();
        textArea.setEditable(false);

        if (riwayatPenjualan.isEmpty()) {
            textArea.append("Belum ada transaksi penjualan.\n");
        } else {
            for (String transaksi : riwayatPenjualan) {
                textArea.append(transaksi + "\n");
            }
        }

        JScrollPane scrollPane = new JScrollPane(textArea);
        riwayatFrame.add(scrollPane);
        riwayatFrame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(InventoryApp::new);
    }
}
